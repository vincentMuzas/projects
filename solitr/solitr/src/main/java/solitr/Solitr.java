package solitr;

import solitr.Card;
import java.util.ArrayList;
import java.util.Collections;

import solitr.Displayer;


/**
 * Solitr
 */
public class Solitr {

	private Displayer displayer;
	private ArrayList<Card> deck = new ArrayList<Card>();
	private ArrayList<Card> column1 = new ArrayList<Card>();
	private ArrayList<Card> column2 = new ArrayList<Card>();
	private ArrayList<Card> column3 = new ArrayList<Card>();
	private ArrayList<Card> column4 = new ArrayList<Card>();
	private ArrayList<Card> column5 = new ArrayList<Card>();
	private ArrayList<Card> column6 = new ArrayList<Card>();
	private ArrayList<Card> column7 = new ArrayList<Card>();
	private ArrayList<Card> pile1 = new ArrayList<Card>();
	private ArrayList<Card> pile2 = new ArrayList<Card>();
	private ArrayList<Card> pile3 = new ArrayList<Card>();
	private ArrayList<Card> pile4 = new ArrayList<Card>();

	public Solitr() {
		displayer = new Displayer();
		createDeck();
		distributeCards();
		refreshDisplay();
		System.out.println("initialisation done");
	}

	private void addArray(ArrayList<Card> arr) {
		for (int i = 0; i < arr.size(); i++) {
			displayer.content.setComponentZOrder(arr.get(i), 0);
		}
	}

	public void refreshDisplay() {
		addArray(deck);
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
				this.deck.add(new Card(value, familly, familly % 2));
				displayer.content.add(deck.get(deck.size() - 1)); //commenter ici
			}
		}
	}

	private void giveCardsTo(int n, ArrayList<Card> array) {
		Card loc;
		for (int i = 0; i < n; i++) {
			loc = deck.get(0);
			loc.setPosition(n - 1 , i + 1);
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
}