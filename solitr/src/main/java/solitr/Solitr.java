package solitr;

import solitr.Card;
import solitr.Displayer;

import java.awt.Rectangle;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.Collections;



/**
 * Solitr
 */
public class Solitr {

	public Displayer displayer;
	public ArrayList<Card> deck = new ArrayList<Card>();
	private ArrayList<Card> deckShow = new ArrayList<Card>();
	public ArrayList<Card> dummies = new ArrayList<Card>();
	private ArrayList<Card> column1 = new ArrayList<Card>();
	private ArrayList<Card> column2 = new ArrayList<Card>();
	private ArrayList<Card> column3 = new ArrayList<Card>();
	private ArrayList<Card> column4 = new ArrayList<Card>();
	private ArrayList<Card> column5 = new ArrayList<Card>();
	private ArrayList<Card> column6 = new ArrayList<Card>();
	private ArrayList<Card> column7 = new ArrayList<Card>();
	public ArrayList<Card> pile1 = new ArrayList<Card>();
	public ArrayList<Card> pile2 = new ArrayList<Card>();
	public ArrayList<Card> pile3 = new ArrayList<Card>();
	public ArrayList<Card> pile4 = new ArrayList<Card>();
	private ArrayList<Card> selected = new ArrayList<Card>();
	private ArrayList<Card> removeFrom;

	public Solitr() {
		displayer = new Displayer();
		createDummyCards();
		createDeck();
		distributeCards();
		decklistener();
		refreshDisplay();
		displayer.setVisible(true);
	}

	private void createDummyCards() {
		dummies.add(new DummyCard(0, 0, this, deck, false));
		dummies.get(0).addMouseListener(refreshDeck);
		dummies.add(new DummyCard(1, 0, this, column1, true));
		dummies.add(new DummyCard(1, 1, this, column2, true));
		dummies.add(new DummyCard(1, 2, this, column3, true));
		dummies.add(new DummyCard(1, 3, this, column4, true));
		dummies.add(new DummyCard(1, 4, this, column5, true));
		dummies.add(new DummyCard(1, 5, this, column6, true));
		dummies.add(new DummyCard(1, 6, this, column7, true));
		dummies.add(new DummyCard(0, 4, this, pile1, false));
		dummies.add(new DummyCard(0, 3, this, pile2, false));
		dummies.add(new DummyCard(0, 5, this, pile3, false));
		dummies.add(new DummyCard(0, 6, this, pile4, false));
	}

	private void addArray(ArrayList<Card> arr) {
		for (int i = 0; i < arr.size(); i++) {
			displayer.content.setComponentZOrder(arr.get(i), 0);
		}
	}

	public void refreshDisplay() {
		addArray(dummies);
		addArray(deck);
		addArray(deckShow);
		addArray(column1);
		addArray(column2);
		addArray(column3);
		addArray(column4);
		addArray(column5);
		addArray(column6);
		addArray(column7);
		addArray(pile1);
		addArray(pile2);
		addArray(pile3);
		addArray(pile4);
	}

	private void createDeck() {
		for (int familly = 0; familly < 4; familly++) {
			for (int value = 0; value < 13; value++) {
				this.deck.add(new Card(value, familly, familly % 2, this));
				displayer.content.add(deck.get(deck.size() - 1));
			}
		}
	}

	private void giveCardsTo(int n, ArrayList<Card> array) {
		Card loc;
		for (int i = 0; i < n; i++) {
			loc = deck.get(0);
			loc.setPosition(n - 1 , i + 1);
			loc.addMouseListener(selectCard);
			array.add(loc);
			deck.remove(0);
		}
		array.get(array.size() - 1).setHidden(false);
	}

	private void distributeCards() {
		Collections.shuffle(deck);
		giveCardsTo(1, column1);
		giveCardsTo(2, column2);
		giveCardsTo(3, column3);
		giveCardsTo(4, column4);
		giveCardsTo(5, column5);
		giveCardsTo(6, column6);
		giveCardsTo(7, column7);
	}

	private void decklistener() {
		for (int i = 0; i < deck.size(); i++) {
			deck.get(i).addMouseListener(this.listener);
		}
	}

	//prochaine carte du deck
	public MouseListener listener = new MouseAdapter() {
		public void mouseClicked(MouseEvent e) {
			Card card = deck.get(0);
			deckShow.add(card);
			deck.remove(0);
			for( MouseListener al : card.getMouseListeners() ) {
				card.removeMouseListener( al );
			}
			card.addMouseListener(selectCard);
			card.setPosition(1, 0);
			card.setHidden(false);
			refreshDisplay();
		}
	};

	//déplace les elements sélectionées sur la colonne contenant elem
	private void moveCard(Card elem, ArrayList<ArrayList<Card>> list) {
		list.remove(deck);
		list.remove(deckShow);
		if (!elem.checkDeplacement(selected.get(0))) {
			selected.clear();
			return;
		}
		ArrayList<Card> toTransfer = null;
		ArrayList<ArrayList<Card>> piles = new ArrayList<>();
		piles.add(pile1); piles.add(pile2); piles.add(pile3); piles.add(pile4);
		for (int i = 0; i < list.size();i++) {
			if (list.get(i).indexOf(elem) != -1)
				toTransfer = list.get(i);
		}
		Boolean isPile = false;
		if (piles.contains(toTransfer))
			isPile = true;

		if (toTransfer != null || toTransfer == removeFrom) {
			for (int i = 0; i < selected.size(); i++) {
				removeFrom.remove(selected.get(i));
				toTransfer.add(selected.get(i));
			}
			int posx = toTransfer.get(0).getBounds().x;
			for (int i = 0; i < toTransfer.size(); i++) {
				if (!isPile)
					toTransfer.get(i).setBounds(posx, 150 + 35 * (i + 1), 100, 142);
				else
					toTransfer.get(i).setBounds(posx, 10, 100, 142);
			}
		}
		if (removeFrom.size() > 0)
			removeFrom.get(removeFrom.size() - 1).setHidden(false);
		selected.clear();
	}

	public void findAndSelect(Card elem) {
		ArrayList<ArrayList<Card>> list = new ArrayList<>();
		list.add(deck); list.add(deckShow); list.add(dummies);
		list.add(column1); list.add(column2); list.add(column3);
		list.add(column4);  list.add(column5); list.add(column6); 
		list.add(column7); list.add(pile1); list.add(pile2);
		list.add(pile3); list.add(pile4);
		if (!selected.isEmpty()) {
			moveCard(elem, list);
			refreshDisplay();
			return;
		}
		selected.clear();

		int index;
		for (int i = 0; i < list.size(); i++) {
			if ((index = list.get(i).indexOf(elem)) != -1) {
				removeFrom = list.get(i);
				for (; index < list.get(i).size(); index ++) {
					selected.add(list.get(i).get(index));
					//list.get(i).get(index).setBorder(BorderFactory.createMatteBorder(3, 3, 3, 3, Color.red));
				}
				break;
			}
		}
		refreshDisplay();
	}

	public MouseListener selectCard = new MouseAdapter() {
		public void mouseClicked(MouseEvent e) {
			findAndSelect((Card) e.getComponent());
		}
	};

	public MouseListener refreshDeck = new MouseAdapter() {
		public void mouseClicked(MouseEvent e) {
			
			Card card;
			while (deckShow.size() > 0) {
				card = deckShow.get(0);
				for( MouseListener al : card.getMouseListeners() ) {
					card.removeMouseListener( al );
				}
				card.addMouseListener(listener);
				card.setHidden(true);
				card.setPosition(0, 0);
				deck.add(card);
				deckShow.remove(card);
			}
			refreshDisplay();
			System.out.println("deck refreshed " + deck.size() + " cards");
		}
	};

	private void moveToDummy(DummyCard elem) {
		ArrayList<ArrayList<Card>> list = new ArrayList<>();
		list.add(deckShow); list.add(column1); list.add(column2);
		list.add(column3); list.add(column4); list.add(column5);
		list.add(column6); list.add(column7); list.add(pile1);
		list.add(pile2); list.add(pile3); list.add(pile4);
		ArrayList<Card> toTransfer = elem.list;

		if (elem.checkDeplacement(selected.get(0))) {
			for (int i = 0; i < selected.size(); i++)
			{
				removeFrom.remove(selected.get(i));
				toTransfer.add(selected.get(i));
			}
			Rectangle bounds = elem.getBounds();
			for (int i = 0; i < toTransfer.size(); i++) {
				toTransfer.get(i).setBounds(bounds);
				if (elem.isColumn)
					bounds.y += 35;
			}
			if (removeFrom.size() > 0)
				removeFrom.get(removeFrom.size() - 1).setHidden(false);
		}
		selected.clear();
	}

	public MouseListener dummyListener = new MouseAdapter() {
		public void mouseClicked(MouseEvent e) {
			if (selected.size() > 0)
				moveToDummy((DummyCard) e.getComponent());
		}
	};

}