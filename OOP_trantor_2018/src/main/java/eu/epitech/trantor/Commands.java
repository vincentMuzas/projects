package eu.epitech.trantor;

/**
 * Commands
 */
public class Commands {

	// #region Properties

	private Map map;
	private LookAction[] lookAction = new LookAction[] { 
		new LookAction() { public String look(Drone drone, Item item) { return lookTop(drone); } },
		new LookAction() { public String look(Drone drone, Item item) { return lookRight(drone); } },
		new LookAction() { public String look(Drone drone, Item item) { return lookBot(drone); } },
		new LookAction() { public String look(Drone drone, Item item) { return lookLeft(drone); } }
	};
	private CommandsAction[] commandsAction = new CommandsAction[] { 
		new CommandsAction() { public String doCommand(Drone drone, Item item) { return forward(drone, item); } },
		new CommandsAction() { public String doCommand(Drone drone, Item item) { return right(drone, item); } },
		new CommandsAction() { public String doCommand(Drone drone, Item item) { return left(drone, item); } },
		new CommandsAction() { public String doCommand(Drone drone, Item item) { return drop(drone, item); } },
		new CommandsAction() { public String doCommand(Drone drone, Item item) { return take(drone, item); } },
		new CommandsAction() { public String doCommand(Drone drone, Item item) { return inventory(drone, item); } },
		new CommandsAction() { public String doCommand(Drone drone, Item item) { return look(drone, item); } },
		new CommandsAction() { public String doCommand(Drone drone, Item item) { return elevation(drone, item); } },
		new CommandsAction() { public String doCommand(Drone drone, Item item) { return broadcast(drone, item); } }
	};

	// #endregion

	// #region Constructor

	interface LookAction {
		String look(Drone drone, Item item);
	}

	interface CommandsAction {
		String doCommand(Drone drone, Item item);
	}

	public Commands(Map map) {
		this.map = map;
	}

	// #endregion

	// #region Methods

	/**
	 * Method to call command
	 * 
	 * @param parameter complete command from client (ex : "drop linemate")
	 * @param drone     calling command
	 * @return string value ("ko" or "ok" or command form)
	 */
	public String handleCommand(String parameter, Drone drone) {
		String result = new String();
		String[] params = parameter.split(" ");
		if (params.length > 2) {
			return "ko";
		}
		String command = params[0];
		String param = new String();
		if (params.length > 1) {
			param = params[1];
		}
		Integer idCommand = getCommandId(command);
		if (idCommand == -1) {
			return "invalid command";
		}
		Item item = Item.generateItemByString(param);
		result = this.commandsAction[idCommand].doCommand(drone, item);
		return result;
	}

	/**
	 * Get command id by command
	 * 
	 * @param command to get id
	 * @return id of command
	 */
	public Integer getCommandId(String command) {
		java.util.ArrayList<String> listCommand = new java.util.ArrayList<String>() {
			{
				add("Forward");
				add("Right");
				add("Left");
				add("Drop");
				add("Take");
				add("Inventory");
				add("Look");
				add("Incantation");
				add("Broadcast");
			}
		};
		for (int i = 0; i < listCommand.size(); i++) {
			if (listCommand.get(i).equals(command)) {
				return i;
			}
		}
		return -1;
	}

	/**
	 * Command to move forward (1 range)
	 * 
	 * @param drone to move forward
	 */
	public String forward(Drone drone, Item item) {
		if (item != null) {
			return "ko";
		}
		switch (drone.getOrientation()) {
			case 1:
				drone.setPosY(drone.getPosY() - 1 < 0 ? (this.map.getSizeY() - 1) : drone.getPosY() - 1);
				break;
			case 2:
				drone.setPosX(drone.getPosX() + 1 > (this.map.getSizeX() - 1) ? 0 : drone.getPosX() + 1);
				break;
			case 3:
				drone.setPosY(drone.getPosY() + 1 > (this.map.getSizeY() - 1) ? 0 : drone.getPosY() + 1);
				break;
			case 4:
				drone.setPosX(drone.getPosX() - 1 < 0 ? (this.map.getSizeX() - 1) : drone.getPosX() - 1);
				break;
			}
		return "ok";
	}

	/**
	 * Command to move at right
	 * 
	 * @param drone to move right
	 */
	public String right(Drone drone, Item item) {
		if (item != null) {
			return "ko";
		}
		Integer orientation = drone.getOrientation();
		drone.setOrientation(orientation == 4 ? 1 : orientation + 1);
		return "ok";
	}

	/**
	 * Command to move at left
	 * 
	 * @param drone to move left
	 */
	public String left(Drone drone, Item item) {
		if (item != null) {
			return "ko";
		}
		Integer orientation = drone.getOrientation();
		drone.setOrientation(orientation == 1 ? 4 : orientation - 1);
		return "ok";
	}

	/**
	 * Command to drop item in inventory at map
	 * 
	 * @param drone to drop
	 * @param item  to drop
	 */
	public String drop(Drone drone, Item item) {
		if (item == null) {
			return "ko";
		}
		if (drone.countItem(item) == 0) {
			return "ko";
		}
		drone.removeToInventory(item);
		Case[][] map = this.map.getMap();
		map[drone.getPosX()][drone.getPosY()].addToItems(item);
		return "ok";
	}

	/**
	 * Command to take item on map and add to inventory of drone
	 * 
	 * @param drone to take item
	 * @param item  to take
	 */
	public String take(Drone drone, Item item) {
		if (item == null) {
			return "ko";
		}
		Case[][] map = this.map.getMap();
		Item newItem = map[drone.getPosX()][drone.getPosY()].removeItem(item);
		if (newItem != null) {
			drone.addToInventory(newItem);
			return "ok";
		}
		return "ko";
	}

	/**
	 * Command inventory
	 * 
	 * @param drone to get inventory
	 * @return String of inventory
	 */
	public String inventory(Drone drone, Item item) {
		if (item != null) {
			return "ko";
		}
		String result = new String();
		result += "[";
		Integer i = 0;
		for (java.util.Map.Entry<Integer, Integer> entry : drone.getInventory().entrySet()) {
			Item itemEntry = Item.generateItemById(entry.getKey());
			Integer amount = entry.getValue();
			result += itemEntry.getEntitled() + " " + amount;
			if (i < drone.getInventory().size() - 1) {
				result += ", ";
			}
			i++;
		}
		result += "]";
		return result;
	}

	// #region Look

	/**
	 * Command to look depends to drone orientation
	 * 
	 * @param drone to look
	 * @return String of look
	 */
	public String look(Drone drone, Item item) {
		String result = new String();
		if (item != null) {
			return "ko";
		}
		result += "[";
		result += this.lookAction[drone.getOrientation() - 1].look(drone, item);
		result += "]";
		return result.replace(result.substring(result.lastIndexOf(",")), "]");
	}

	/**
	 * Command to look at top
	 * 
	 * @param drone to look
	 * @return String of look
	 */
	public String lookTop(Drone drone) {
		String result = new String();
		Integer x = 0;
		Integer y = 0;
		Case[][] map = this.map.getMap();

		for (int y1 = 0; y1 <= drone.getLevel(); y1++) {
			for (int x1 = -y1; x1 <= y1; x1++) {
				if (drone.getPosX() + x1 < 0)
					x = (this.map.getSizeX() - 1) + x1;
				else if (drone.getPosX() + x1 > (this.map.getSizeX() - 1))
					x = 0 + x1;
				else
					x = drone.getPosX() + x1;
				if (drone.getPosY() - y1 < 0)
					y = (this.map.getSizeY() - 1) - y1;
				else if (drone.getPosY() - y1 > (this.map.getSizeY() - 1))
					y = 0 + y1;
				else
					y = drone.getPosY() - y1;

				result += map[x][y].toString();
				result += ", ";
			}
		}
		return result;
	}

	/**
	 * Command to look at right
	 * 
	 * @param drone to look
	 * @return String of look
	 */
	public String lookRight(Drone drone) {
		String result = new String();
		Integer x = 0;
		Integer y = 0;
		Case[][] map = this.map.getMap();

		for (int x1 = 0; x1 <= drone.getLevel(); x1++)
			for (int y1 = x1; y1 >= -x1; y1--) {
				if (drone.getPosX() + x1 < 0)
					x = (this.map.getSizeX() - 1) + x1;
				else if (drone.getPosX() + x1 > (this.map.getSizeX() - 1))
					x = 0 + x1;
				else
					x = drone.getPosX() + x1;
				if (drone.getPosY() - y1 < 0)
					y = (this.map.getSizeY() - 1) - y1;
				else if (drone.getPosY() - y1 > (this.map.getSizeY() - 1))
					y = 0 + y1;
				else
					y = drone.getPosY() - y1;
				result += map[x][y].toString();
				result += ", ";
			}
		return result;
	}

	/**
	 * Command to look at bottom
	 * 
	 * @param drone to look
	 * @return String of look
	 */
	public String lookBot(Drone drone) {
		String result = new String();
		Integer x = 0;
		Integer y = 0;
		Case[][] map = this.map.getMap();

		for (int y1 = 0; y1 <= drone.getLevel(); y1++) {
			for (int x1 = y1; x1 >= -y1; x1--) {
				if (drone.getPosX() + x1 < 0)
					x = (this.map.getSizeX() - 1) + x1;
				else if (drone.getPosX() + x1 > (this.map.getSizeX() - 1))
					x = 0 + x1;
				else
					x = drone.getPosX() + x1;
				if (drone.getPosY() + y1 < 0)
					y = (this.map.getSizeY() - 1) + y1;
				else if (drone.getPosY() + y1 > (this.map.getSizeY() - 1))
					y = 0 + y1;
				else
					y = drone.getPosY() + y1;
				result += map[x][y].toString();
				result += ", ";
			}
		}
		return result;
	}

	/**
	 * Command to look at left
	 * 
	 * @param drone to look
	 * @return String of look
	 */
	public String lookLeft(Drone drone) {
		String result = new String();
		Integer x = 0;
		Integer y = 0;
		Case[][] map = this.map.getMap();

		for (int x1 = 0; x1 <= drone.getLevel(); x1++) {
			for (int y1 = -x1; y1 <= x1; y1++) {
				if (drone.getPosX() - x1 < 0)
					x = (this.map.getSizeX() - 1) - x1;
				else if (drone.getPosX() - x1 > (this.map.getSizeX() - 1))
					x = 0 - x1;
				else
					x = drone.getPosX() - x1;
				if (drone.getPosY() - y1 < 0)
					y = (this.map.getSizeY() - 1) - y1;
				else if (drone.getPosY() - y1 > (this.map.getSizeY() - 1))
					y = 0 - y1;
				else
					y = drone.getPosY() - y1;
				result += map[x][y].toString();
				result += ", ";
			}
		}
		return result;
	}

	// #endregion

	// #region elevation

	/**
	 * Command to check the level
	 * 
	 * @param drone to check
	 * @return true / false
	 */
	public String elevation(Drone drone, Item item) {

		int[][] tab = { 
			{ 1, 1, 0, 0, 0, 0, 0 }, 
			{ 2, 1, 1, 1, 0, 0, 0 },
			{ 2, 2, 0, 1, 0, 2, 0 },
			{ 4, 1,	1, 2, 0, 1, 0 },
			{ 4, 1, 2, 1, 3, 0, 0 },
			{ 6, 1, 2, 3, 0, 1, 0 },
			{ 6, 2, 2, 2, 2, 2, 1 } 
		};
		for (int i = 1; i < 7; i++) {
			int stock = tab[drone.getLevel() - 1][i];
			if (drone.countItem(Item.generateItemById(i)) < stock)
				return "ko";
		}

		for (int i = 1; i < 7; i++) {
			int stock = tab[drone.getLevel() - 1][i];
			drone.removeToInventory(Item.generateItemById(i), stock);
		}

		drone.setLevel(drone.getLevel() + 1);
		return "ok";
	}

	// #endregion

	/**
	 * Command to check the level
	 * @param drone to check
	 * @return true / false
	 */
	public String ejection(Drone drone, Item item) {
		if (item != null) {
			return "ko";
		}	
		Case[][] map = this.map.getMap();
		Case box = map[drone.getPosX()][drone.getPosY()];
		
		for (Drone player : box.getDrones()) {
			if (player.getId() != drone.getId()) {
				switch (drone.getOrientation()) {
					case 1:
						player.setPosY(drone.getPosY() - 1 < 0 ? (this.map.getSizeY() - 1) : drone.getPosY() - 1);
						break;  
					case 2:
						player.setPosX(drone.getPosX() + 1 > (this.map.getSizeX() - 1) ? 0 : drone.getPosX() + 1);
						break;
					case 3:
						player.setPosY(drone.getPosY() + 1 > (this.map.getSizeY() - 1) ? 0 : drone.getPosY() + 1);
						break;
					case 4:
						player.setPosX(drone.getPosX() - 1 < 0 ? (this.map.getSizeX() - 1) : drone.getPosX() - 1);
						break;
				}
			}
		}
		return "ok";
	}

	/**
	 * Command to talk with other drones
	 * @param drone to execute command
	 * @param item // TODO : Change for String params
	 * @return String "ok"
	 */
	public String broadcast(Drone drone, Item item) {

		return "Not implemented";
	}

	// #endregion

	// #endregion
}
