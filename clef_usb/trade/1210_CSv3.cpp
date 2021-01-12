	//+------------------------------------------------+
	//|                          Strategy: 1210_CS.mq5 |
	//|                            Created by Cephitec |
	//|                            http://cephitec.com |
	//+------------------------------------------------+

	#property copyright "Created by Cephitec"
	#property link      "http://cephitec.com"
	#property version   "1.00"
	#property description ""

	//+-------------------------------------------------------------------------+
	//|                              1 - INPUTS                                 |
	//+-------------------------------------------------------------------------+

		input bool		Audible_Alerts = true; 			// Alertes Audibles (true/false)
		input bool		close_eow_20h = false;			// fermer toutes les position vendredi à 20H et reprend lundi à 09H (true/false)
		input bool		time = false; 					// Prendre en compte les horaires (true/false) 
		input bool		Buy = true;						// autorise la prise de position d'achat
		input bool		Sell = true;					// autorise la prise de position de vente

		// Intervalle de Trade

		int				TOD_From_Hour = 09; 			// Heure de DÉBUT de trade
		int				TOD_From_Min = 00; 				// Minute de DÉBUT de trade
		int				TOD_To_Hour = 20; 				// Heure de FIN de trade
		int				TOD_To_Min = 00; 				// Minute de FIN de trade

		// Contre-Signal

		int 			cs_first_tp = 5;				// Take Profit
		int 			cs_first_sl = 7;				// Stop Loss
		int 			cs_second_tp = 15;				// Take Profit (2éme Tier)
		int 			cs_second_sl = 7;				// Stop Loss (2éme Tier)
		int 			cs_third_tp = 80;				// Take Profit (3éme Tier)
		int 			cs_third_sl = 0;				// Stop Loss (3éme Tier)
		int				MaximumLongTradeDuration = 28; 	// Nombre de bougies avant de changer d'objectifs

		// Money Managment

		int				MaxOpenTrades = 2;				// Nombre de positions simultanées

		int				MaxLongTrades = 1000;			// durée maximale d'une position longue (?)
		int				MaxShortTrades = 1000;			// durée maximale d'une position courte (?)
		int				MaxPendingOrders = 1000;
		int				NextOpenTradeAfterBars = 5;		//next open trade after time

	//+-------------------------------------------------------------------------+
	//|                             2 - GLOBALES                                |
	//+-------------------------------------------------------------------------+

		int				LotDigits;
		int				MagicNumber = 1947083;
		datetime		LastTradeTime = 0;
		double 			TradeSize = 1;
		int				MaxSlippage = 3;
		int				MaxSlippage_;
		bool			crossed[2];
		bool			Hedging = true;
		int				OrderRetry = 2, OrderWait = 2;
		double			myPoint;
		int				MA_handle, ADX_handle;
		double			MA[], ADX_PlusDI[], ADX_MinusDI[];
		double			HighM2[], LowM2[], CloseM2[];


		double			TP = 0, SL = 0;
		double			price = 0;
		ENUM_ORDER_TYPE	lastTypeUsed = 0;
		ulong			ticket = 0;

		int 			total_trade = 0;
		double 			solde_j1 = 0;

	//+-------------------------------------------------------------------------+
	//|                             4 - EABUILDER                               |
	//+-------------------------------------------------------------------------+

		bool			inTimeInterval(datetime t, int from_hour, int from_min, int to_hour, int to_min) {
			string TOD = TimeToString(t, TIME_MINUTES);
			string TOD_From = StringFormat("%02d", from_hour) + ":" + StringFormat("%02d", from_min);
			string TOD_To = StringFormat("%02d", to_hour) + ":" + StringFormat("%02d", to_min);
			return((StringCompare(TOD, TOD_From) >= 0 && StringCompare(TOD, TOD_To) <= 0) || (StringCompare(TOD_From, TOD_To) > 0
				&& ((StringCompare(TOD, TOD_From) >= 0 && StringCompare(TOD, "23:59") <= 0)
				|| (StringCompare(TOD, "00:00") >= 0 && StringCompare(TOD, TOD_To) <= 0))));
		}

		bool			Cross(int i, bool condition) { //returns true if "condition" is true and was false in the previous call
			bool ret = condition && !crossed[i];
			crossed[i] = condition;
			return(ret);
		}

		void			myAlert(string type, string message) {
			if (type == "error") {
				Print(type + " | 3B SIGNAL @ " + (string)Symbol() + "," + (string)Period() + " | " + message);
				if (Audible_Alerts)
					Alert(type + " | 3B SIGNAL @ " + (string)Symbol() + "," + (string)Period() + " | " + message);
			}
		}

		int				TradesCount(ENUM_ORDER_TYPE type) { //returns # of open trades for order type, current symbol and magic number
			if(type <= 1)
			{
				if (PositionSelect(Symbol()) && PositionGetInteger(POSITION_MAGIC) == MagicNumber && PositionGetInteger(POSITION_TYPE) == type)
					return(1);
				else
					return(0);
			}
			else
			{
				int result = 0;
				int total = OrdersTotal();
				for(int i = 0; i < total; i++)
				{
					if(OrderGetTicket(i) <= 0) continue;
					if(OrderGetInteger(ORDER_MAGIC) != MagicNumber || OrderGetString(ORDER_SYMBOL) != Symbol() || OrderGetInteger(ORDER_TYPE) != type) continue;
					result++;
				}
				return(result);
			}
		}

		ulong			myOrderSend(ENUM_ORDER_TYPE type, double loc_price, double volume, string ordername) { //send order, return ticket ("loc_price" is irrelevant for market orders)
			if(!TerminalInfoInteger(TERMINAL_TRADE_ALLOWED) || !MQLInfoInteger(MQL_TRADE_ALLOWED)) return(0);
			int retries = 0;
			int long_trades = TradesCount(ORDER_TYPE_BUY);
			int short_trades = TradesCount(ORDER_TYPE_SELL);
			int long_pending = TradesCount(ORDER_TYPE_BUY_LIMIT) + TradesCount(ORDER_TYPE_BUY_STOP) + TradesCount(ORDER_TYPE_BUY_STOP_LIMIT);
			int short_pending = TradesCount(ORDER_TYPE_SELL_LIMIT) + TradesCount(ORDER_TYPE_SELL_STOP) + TradesCount(ORDER_TYPE_SELL_STOP_LIMIT);
			string ordername_ = ordername;
			
			if (ordername != "")
				ordername_ = "(" + ordername + ")";
			
			if(!Hedging && ((type % 2 == 0 && short_trades + short_pending > 0) || (type % 2 == 1 && long_trades + long_pending > 0))) {
				myAlert("print", "Order"+ordername_+" not sent, hedging not allowed");
				return(0);
			}

			if((type % 2 == 0 && long_trades >= MaxLongTrades) || (type % 2 == 1 && short_trades >= MaxShortTrades)
				|| (long_trades + short_trades >= MaxOpenTrades) || (type > 1 && long_pending + short_pending >= MaxPendingOrders)) {
				myAlert("print", "Order" + ordername_ + " not sent, maximum reached");
				return(0);
			}

			MqlTradeRequest request = {0};
			request.action = (type <= 1) ? TRADE_ACTION_DEAL : TRADE_ACTION_PENDING;

			int filling = (int)SymbolInfoInteger(Symbol(), SYMBOL_FILLING_MODE);
			if (request.action == TRADE_ACTION_DEAL && (filling & 1) != 1)
				request.type_filling = ORDER_FILLING_IOC;

			request.magic = MagicNumber;
			request.symbol = Symbol();
			request.volume = NormalizeDouble(volume, LotDigits);
			if (type == ORDER_TYPE_SELL) {
				request.sl = NormalizeDouble(SL + pips(1), Digits());
				request.tp = NormalizeDouble(TP - pips(1), Digits());
			}
			else {
				request.sl = NormalizeDouble(SL - pips(1), Digits());
				request.tp = NormalizeDouble(TP + pips(1), Digits());
			}
			request.deviation = MaxSlippage_;
			request.type = type;
			request.comment = ordername;
			MqlTradeResult result={0};
			while(!OrderSuccess(result.retcode) && retries < OrderRetry+1)
			{
				MqlTick last_tick;
				SymbolInfoTick(Symbol(), last_tick);
				if(type == ORDER_TYPE_BUY)
					loc_price = last_tick.ask;
				else if(type == ORDER_TYPE_SELL)
					loc_price = last_tick.bid;
				else if(loc_price < 0) {
					myAlert("order", "Order" + ordername_ + " not sent, invalid price for pending order");
					return(0);
				}
				request.price = NormalizeDouble(loc_price, Digits());     
				if (OrderSend(request, result) == true){}
				if (!OrderSuccess(result.retcode)) {
					myAlert("print", "OrderSend" + ordername_ + " error: " + result.comment);
					Sleep(OrderWait * 1000);
				}
				retries++;
			}
			if (!OrderSuccess(result.retcode)) {
				myAlert("error", "OrderSend" + ordername_ + " failed " + (string)(OrderRetry + 1) + " times; error: " + result.comment);
				return(0);
			}
			string typestr[8] = {"Buy", "Sell", "Buy Limit", "Sell Limit", "Buy Stop", "Sell Stop", "Buy Stop Limit", "Sell Stop Limit"};
			myAlert("order", "Order sent" + ordername_ + ": " + typestr[type] + " " + (string)Symbol() + " Magic #" + (string)MagicNumber);

			return((type <= 1) ? result.deal : result.order);
		}

		int				myOrderModifyRel(ENUM_ORDER_TYPE type, ulong loc_ticket, double loc_SL, double loc_TP) { //works for positions and orders, modify SL and TP (relative to open price), zero targets do not modify, ticket is irrelevant for open positions
			if(!TerminalInfoInteger(TERMINAL_TRADE_ALLOWED) || !MQLInfoInteger(MQL_TRADE_ALLOWED))
				return(-1);
			
			int retries = 0;
			int err = 0;
			
			loc_SL = NormalizeDouble(loc_SL, Digits());
			loc_TP = NormalizeDouble(loc_TP, Digits());
			
			if (loc_SL < 0) loc_SL = 0;
			if (loc_TP < 0) loc_TP = 0;
			
			//prepare to select order
			if((type <= 1 && !PositionSelect(Symbol())) || (type > 1 && !OrderSelect(loc_ticket))) {
				err = GetLastError();
				myAlert("error", "PositionSelect / OrderSelect failed; error #" + (string)err);
				return(-1);
			}

			//ignore open positions other than "type"
			if (type <= 1 && PositionGetInteger(POSITION_TYPE) != type) return(0);
			
			//prepare to modify order, convert relative to absolute
			double openprice = (type <= 1) ? PositionGetDouble(POSITION_PRICE_OPEN) : OrderGetDouble(ORDER_PRICE_OPEN);
			double currentSL = (type <= 1) ? PositionGetDouble(POSITION_SL) : OrderGetDouble(ORDER_SL);
			double currentTP = (type <= 1) ? PositionGetDouble(POSITION_TP) : OrderGetDouble(ORDER_TP);
			
			if(NormalizeDouble(loc_SL, Digits()) == 0) loc_SL = currentSL; //not to modify
			if(NormalizeDouble(loc_TP, Digits()) == 0) loc_TP = currentTP; //not to modify
			if(NormalizeDouble(loc_SL - currentSL, Digits()) == 0 && NormalizeDouble(loc_TP - currentTP, Digits()) == 0)
				return(0); //nothing to do
			
			MqlTradeRequest request = {0};
			
			request.action = (type <= 1) ? TRADE_ACTION_SLTP : TRADE_ACTION_MODIFY;
			if (type > 1)
				request.order = loc_ticket;
			else
				request.position = loc_ticket;
			request.symbol = Symbol();
			request.price = (type <= 1) ? PositionGetDouble(POSITION_PRICE_OPEN) : OrderGetDouble(ORDER_PRICE_OPEN);
			if (type == ORDER_TYPE_SELL) {
				request.sl = NormalizeDouble(SL + pips(1), Digits());
				request.tp = NormalizeDouble(TP - pips(1), Digits());
			}
			else {
				request.sl = NormalizeDouble(SL - pips(1), Digits());
				request.tp = NormalizeDouble(TP - pips(1), Digits());
			}
			
			MqlTradeResult result = {0};
			
			while(!OrderSuccess(result.retcode) && retries < OrderRetry+1)
			{
				if (OrderSend(request, result) == true){}
				if(!OrderSuccess(result.retcode)){
					err = GetLastError();
					myAlert("print", "OrderModifyRel error #" + (string)err);
					Sleep(OrderWait*1000);
				}
				retries++;
			}
			if(!OrderSuccess(result.retcode)) {
				myAlert("error", "OrderModifyRel failed " + (string)(OrderRetry + 1) + " times; error #" + (string)err);
				return(-1);
			}

			string alertstr = "Order modify: ticket=" + (string)loc_ticket;	
			if(NormalizeDouble(loc_SL, Digits()) != 0) alertstr = alertstr + " SL = " + (string)loc_SL;
			if(NormalizeDouble(loc_TP, Digits()) != 0) alertstr = alertstr + " TP = " + (string)loc_TP;
			myAlert("modify", alertstr);
			return(0);
		}

		void			myOrderClose(ENUM_ORDER_TYPE type, int volumepercent, string ordername, string msg) { 
			if(!TerminalInfoInteger(TERMINAL_TRADE_ALLOWED) || !MQLInfoInteger(MQL_TRADE_ALLOWED)) return;
			if (type > 1) return;
			
			MqlTick last_tick;
			bool success = false;
			string ordername_ = ordername;
			SymbolInfoTick(Symbol(), last_tick);
			
			if (ordername != "")
				ordername_ = "("+ordername+")";
			
			if (!PositionSelect(Symbol())) return;
			if(PositionGetInteger(POSITION_MAGIC) != MagicNumber || PositionGetInteger(POSITION_TYPE) != type) return;
			
			double loc_price = (type == ORDER_TYPE_SELL) ? last_tick.ask : last_tick.bid;
			MqlTradeRequest request = {0};
			request.action = TRADE_ACTION_DEAL;

			//set allowed filling type
			int filling = (int)SymbolInfoInteger(Symbol(),SYMBOL_FILLING_MODE);
			if(request.action == TRADE_ACTION_DEAL && (filling & 1) != 1)
			request.type_filling = ORDER_FILLING_IOC;

			request.magic = MagicNumber;
			request.symbol = Symbol();
			request.volume = NormalizeDouble(PositionGetDouble(POSITION_VOLUME)*volumepercent * 1.0 / 100, LotDigits);
			if (NormalizeDouble(request.volume, LotDigits) == 0) return;
			request.price = NormalizeDouble(loc_price, Digits());
			request.sl = request.tp = 0;
			if (volumepercent != 100) {
				if (type == ORDER_TYPE_BUY) {
					request.tp = TP + pips(1);
					request.sl = SL - pips(1);
				}
				else if (type == ORDER_TYPE_SELL) {
					request.sl = SL + pips(1);
					request.tp = TP - pips(1);
				}
			}
			request.deviation = MaxSlippage_;
			request.type = (ENUM_ORDER_TYPE)(1 - type); //opposite type
			request.comment = ordername;
			MqlTradeResult result = {0};
			if (msg != "")
				myPrint("MyOrderClose : " + msg);
			if (OrderSend(request, result)) {};
			success = OrderSuccess(result.retcode);
			if(!success)
				myAlert("error", "OrderClose"+ordername_+" failed; error: "+result.comment);
			string typestr[8] = {"Buy", "Sell", "Buy Limit", "Sell Limit", "Buy Stop", "Sell Stop", "Buy Stop Limit", "Sell Stop Limit"};
			if(success)
				myAlert("order", "Orders closed"+ordername_+": "+typestr[type]+" "+Symbol()+" Magic #"+ (string)MagicNumber);
			total_trade++;
		}

		bool			OrderSuccess(uint retcode) {
			return(retcode == TRADE_RETCODE_PLACED || retcode == TRADE_RETCODE_DONE || retcode == TRADE_RETCODE_DONE_PARTIAL || retcode == TRADE_RETCODE_NO_CHANGES);
		}

	//+-------------------------------------------------------------------------+
	//|                          5 - INIT FUNCTIONS                             |
	//+-------------------------------------------------------------------------+

		int				OnInit() {
			MaxSlippage_ = MaxSlippage;	
			myPoint = Point();
			
			if(Digits() == 5 || Digits() == 3) {
				myPoint *= 10;
				MaxSlippage_ *= 10;
			}

			//initialize LotDigits
			double LotStep = SymbolInfoDouble(Symbol(), SYMBOL_VOLUME_STEP);
			
			if(LotStep >= 1) LotDigits = 0;
			else if(LotStep >= 0.1) LotDigits = 1;
			else if(LotStep >= 0.01) LotDigits = 2;
			else LotDigits = 3;
			
			//initialize crossed
			for (int i = 0; i < ArraySize(crossed); i++)
				crossed[i] = true;
			
			MA_handle = iMA(NULL, PERIOD_CURRENT, 28, 0, MODE_SMA, PRICE_CLOSE);
			if(MA_handle < 0) return(INIT_FAILED);

			ADX_handle = iADX(NULL, PERIOD_CURRENT, 14);
			if(ADX_handle < 0) return(INIT_FAILED);

			return(INIT_SUCCEEDED);
		}

		void			initAverages() {
			if(CopyBuffer(MA_handle, 0, 0, 30, MA) <= 0) return;
			ArraySetAsSeries(MA, true);
			if(CopyBuffer(ADX_handle, PLUSDI_LINE, 0, 30, ADX_PlusDI) <= 0) return;
			ArraySetAsSeries(ADX_PlusDI, true);
			if(CopyBuffer(ADX_handle, MINUSDI_LINE, 0, 30, ADX_MinusDI) <= 0) return;
			ArraySetAsSeries(ADX_MinusDI, true);
			if(CopyHigh(Symbol(), PERIOD_M2, 0, 35, HighM2) <= 0) return;
			ArraySetAsSeries(HighM2, true);
			if(CopyLow(Symbol(), PERIOD_M2, 0, 35, LowM2) <= 0) return;
			ArraySetAsSeries(LowM2, true);
			if(CopyClose(Symbol(), PERIOD_CURRENT, 0, 200, CloseM2) <= 0) return;
			ArraySetAsSeries(CloseM2, true);
		}

	//+-------------------------------------------------------------------------+
	//|                         6 - GLOBAL FUNCTIONS                            |
	//+-------------------------------------------------------------------------+

		bool			NewBar() {
			datetime	Time[];
			ArraySetAsSeries(Time, true);
			CopyTime(Symbol(), Period(), 0, 1, Time);
			static datetime	LastTime = 0;
			bool ret = Time[0] > LastTime && LastTime > 0;
			LastTime = Time[0];
			return(ret);
		}

		double 			pips(double value) {
			return (value/10000);
		}

		void			myPrint(string msg) {
			if (msg != "")
				Print("●●●●● " + msg);
		}

		double			getHighestPrice(double const &High[], unsigned limit) {
			unsigned i = 1;
			double result = -1;

			while (i < limit) {
				result = High[i] > result ? High[i] : result;
				++i;
			}
			return result;
		}

		double			getLowestPrice(double const &Low[], unsigned limit) {
			unsigned i = 1;
			double result = Low[1];

			while (i < limit) {
				result = Low[i] < result ? Low[i] : result;
				++i;
			}
			return result;
		}

		bool onetime = true;
		bool			check_trade(void)
		{
			MqlDateTime time_st;
			TimeCurrent(time_st);

			if (time_st.hour == 0 && total_trade != 20)
			{
				total_trade = 0;
				solde_j1 = AccountInfoDouble(ACCOUNT_BALANCE);
			}
			if (time_st.hour == 8 && total_trade == 20)
			{
				total_trade = 0;
				solde_j1 = AccountInfoDouble(ACCOUNT_BALANCE);
				onetime = true;
				myPrint("reprise des trades");
				return true;
			}
			else if (total_trade == 20 && solde_j1 < AccountInfoDouble(ACCOUNT_BALANCE))
			{
				if (onetime)
				{
					myPrint("objectifs atteints suspentions des trades jusqu'au lendemain 8H");
					onetime = false;
				}
				return false;
			}
			return true;
		}

	//+-------------------------------------------------------------------------+
	//|                              7 - CS                                     |
	//+-------------------------------------------------------------------------+

		class 			cs
		{
			public:
				cs();
				void		getSignal(bool, double, double);
				bool		checkClose(bool);
				void		refresh(bool, double, double);
				void		rapid_positionChange(double, double);
				void		take_position(double, double);
				void		reset(string, bool);
				void		resolve(double, double);
				bool		check_time(void);

				bool		isAwaitBuyFixed, isAwaitSellFixed;
				bool		tier_one, tier_two, tier_three, orderModified;
				bool 		re_signal;
				bool		tradeResolve;
				int 		onActionBars, bars;
		};

		cs::cs() {
			isAwaitBuyFixed = isAwaitSellFixed = false;
			tier_one = tier_two = tier_three = orderModified = false;
			tradeResolve = false;
			onActionBars = bars = 0;
		}

		bool			cs::check_time(void)
		{
			MqlDateTime time_st;
			TimeCurrent(time_st);

			if (close_eow_20h)
			{
				if ((time_st.day_of_week == 5 && time_st.hour >= 20) || time_st.day_of_week == 0 || (time_st.day_of_week == 1 && time_st.hour <= 8) || time_st.day_of_week == 6)
				{
					if (!tradeResolve)
						reset("Close all position at friday 20h. trading restart monday at 9H", 1);
					return false;
				}
			}
			if (time)
				if (time_st.hour >= 20 || time_st.hour <= 8)
				{
					if (!tradeResolve)
						reset("Close all positions past 20H. tradeing restart next day at 09H", 1);
					return false;
				}
			return true;
		}

		bool			cs::checkClose(bool buy) {
			if ((buy && CloseM2[1] < MA[1] && CloseM2[2] < MA[2]) || (!buy && CloseM2[1] > MA[1] && CloseM2[2] > MA[2]))
				return true;
			return false;
		}

		void			cs::getSignal(bool newBar, double bid, double ask) {
			if ((Cross(0, bid > MA[0]) && ADX_PlusDI[0] > ADX_MinusDI[0] && checkClose(true)) && (!tier_one && !tier_two && !tier_three) && !tradeResolve) {
				isAwaitBuyFixed = true;
				isAwaitSellFixed = false;
			}
			if ((Cross(1, ask < MA[0]) && ADX_PlusDI[0] < ADX_MinusDI[0] && checkClose(false)) && (!tier_one && !tier_two && !tier_three) && !tradeResolve) {
				isAwaitBuyFixed = false;
				isAwaitSellFixed = true;
			}

			if (tradeResolve) {
				if (newBar)
					++bars;
				if (bars == NextOpenTradeAfterBars) {
					myPrint("Possibilité de trade réactivée.");
					tradeResolve = false;
				}
			}
			else
				bars = 0;
		}

		void			cs::refresh(bool newBar, double bid, double ask) {
			if (check_trade() && check_time())
			{
				getSignal(newBar, bid, ask);

				//if (time && !inTimeInterval(TimeCurrent(), TOD_From_Hour, TOD_From_Min, TOD_To_Hour, TOD_To_Min)) return;

				if (newBar && (isAwaitBuyFixed || isAwaitSellFixed) && TerminalInfoInteger(TERMINAL_TRADE_ALLOWED) && MQLInfoInteger(MQL_TRADE_ALLOWED))
					take_position(bid, ask);

				if (newBar && (tier_one || tier_two) && !tradeResolve && !orderModified)
					rapid_positionChange(bid, ask);

				if ((tier_one || tier_two || tier_three) && !tradeResolve)
					resolve(bid, ask);
			}
		}

		void			cs::take_position(double bid, double ask) {
			if (Sell && isAwaitBuyFixed && CloseM2[1] > MA[1] && HighM2[0] > MA[0]) {
				price = bid;
				TP = price - pips(cs_first_tp);
				SL = HighM2[1] + pips(cs_first_sl);
				myPrint("Contre-signal d'ACHAT (TP : " + (string)TP + " / SL : " + (string)SL + ")");
				tier_one = true;
				ticket = myOrderSend(ORDER_TYPE_SELL, price, TradeSize, "");
				lastTypeUsed = ORDER_TYPE_SELL;
				if(ticket == 0) return;
			}
			else if (Buy && isAwaitSellFixed && CloseM2[1] < MA[1] && HighM2[0] < MA[0]) {
				price = ask;
				TP = price + pips(cs_first_tp);
				SL =  LowM2[1] - pips(cs_first_sl);
				myPrint("Contre-signal de VENTE (TP : " + (string)TP + " / SL : " + (string)SL + ")");
				tier_one = true;
				ticket = myOrderSend(ORDER_TYPE_BUY, price, TradeSize, "");
				lastTypeUsed = ORDER_TYPE_BUY;
				if(ticket == 0) return;
			}
			isAwaitSellFixed = isAwaitBuyFixed = false;
		}

		void			cs::rapid_positionChange(double bid, double ask) {
			if (onActionBars >= MaximumLongTradeDuration) {
				myPrint("Limite atteinte (" + (string)MaximumLongTradeDuration + "), changement d'objectifs." + (string)price);
				if (lastTypeUsed == ORDER_TYPE_BUY) {
					if (bid >= price) // Entrain de gagner
						reset("Opération d'achat résolue (Après " + (string)MaximumLongTradeDuration + " bougies).", 1);
					else { // Entrain de perdre
						TP = price;
						myPrint("New TP : " + (string)TP + " / Price : " + (string)price);
						myOrderModifyRel(ORDER_TYPE_BUY, ticket, SL, TP);
						orderModified = true;
					}
				}
				else if (lastTypeUsed == ORDER_TYPE_SELL) {
					if (bid >= price) { // Entrain de perdre
						TP = price;
						myOrderModifyRel(ORDER_TYPE_SELL, ticket, SL, TP);
						orderModified = true;
					}
					else // Entrain de gagner
						reset("Opération de vente résolue (Après " + (string)MaximumLongTradeDuration + " bougies).", 1);
				}
				onActionBars = 0;
			}
			onActionBars += 1;
		}

		void			cs::resolve(double bid, double ask) {
			if (lastTypeUsed == ORDER_TYPE_BUY) {
				if (bid >= TP) {
					if (orderModified)
						reset("Take Profit après modification de l'ordre", 1);
					else if (tier_one) {
						tier_one = false;
						tier_two = true;
						tier_three = false;
						onActionBars = 0;
						myOrderClose(lastTypeUsed, 33, "", "Take Profit - 1er Tier (Buy)");
						price = bid;
						TP = price + pips(cs_second_tp);
						SL = price - pips(cs_second_sl);
						myOrderModifyRel(lastTypeUsed, ticket, SL, TP);
						return;
					}
					else if (tier_two) {
						tier_one = false;
						tier_two = false;
						tier_three = true;
						onActionBars = 0;
						myOrderClose(lastTypeUsed, 50, "", "Take Profit - 2éme Tier (Buy)");
						price = bid;
						TP = pips(1);
						SL = price - pips(cs_second_tp) - pips(cs_first_tp);
						myOrderModifyRel(lastTypeUsed, ticket, SL, TP);
						return;
					}
					//else if (tier_three)
						//reset("Take Profit - 3éme tier (Buy)", 1);
				}
				else if (bid <= SL) {
					if (orderModified)
						reset("Stop Loss après modification de l'ordre", 1);
					else if (tier_one)
						reset("Stop Loss - 1er Tier", 1);
					else if (tier_two)
						reset("Stop Loss - 2éme tier", 1);
					else if (tier_three)
						reset("Stop Loss - 3éme tier", 1);
				}
			}
			else if (lastTypeUsed == ORDER_TYPE_SELL) {
				if (ask <= TP) {
					if (orderModified)
						reset("Gain après modification de l'ordre", 1);
					else if (tier_one) {
						tier_one = false;
						tier_two = true;
						tier_three = false;
						onActionBars = 0;
						myOrderClose(lastTypeUsed, 33, "", "Take Profit - 1er Tier (Sell)");
						price = ask;
						TP = price - pips(cs_second_tp);
						SL = price + pips(cs_second_sl);
						myOrderModifyRel(lastTypeUsed, ticket, SL, TP);
						return;
					}
					else if (tier_two) {
						tier_one = false;
						tier_two = false;
						tier_three = true;
						onActionBars = 0;
						myOrderClose(lastTypeUsed, 50, "", "Take Profit - 2éme Tier (Sell)");
						price = ask;
						TP = pips(1);
						SL = price + pips(cs_second_tp) + pips(cs_first_tp);
						myOrderModifyRel(lastTypeUsed, ticket, SL, TP);
						return;
					}
				}
				else if (ask >= SL) {
					if (orderModified)
						reset("Perte après modification de l'ordre", 1);
					else if (tier_one)
						reset("Stop Loss - 1er Tier", 1);
					else if (tier_two)
						reset("Stop Loss - 2ème Tier", 1);
					else if (tier_three)
						reset("Stop Loss - 3ème Tier", 1);
				}
			}
		}

		void			cs::reset(string msg, bool close) {
			tier_one = tier_two = tier_three = orderModified = false;
			tradeResolve = true;
			SL = TP = 0;
			onActionBars = 0;
			if (close)
			{
				bars = 0;
				myOrderClose(lastTypeUsed, 100, "", "");
			}
			myPrint(msg);
		}

		cs 				counter_signal;

	//+-------------------------------------------------------------------------+
	//|                             8 - TICK                                    |
	//+-------------------------------------------------------------------------+
		void			OnTick()
		{
			MqlTick		last_tick;
			bool		newBar = NewBar();
			SymbolInfoTick(Symbol(), last_tick);

			initAverages();

			counter_signal.refresh(newBar, last_tick.bid, last_tick.ask);
		}
