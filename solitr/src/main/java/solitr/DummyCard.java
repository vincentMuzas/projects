package solitr;
import solitr.Card;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.BorderFactory;


/**
 * DummyCard
 */
public class DummyCard extends Card {

	private static final long serialVersionUID = -1039537051364845845L;
	public ArrayList<Card> list;
	public Boolean isColumn;

	public DummyCard(int row, int column, Solitr ptr, ArrayList<Card> list, Boolean iscolumn) {
		super(0, 0, 0, ptr);
		this.isColumn = iscolumn;
		this.list = list;
		this.setPosition(column, row);
		this.setBorder(BorderFactory.createLoweredBevelBorder());
		this.setBackground(Color.BLACK);
		ptr.displayer.content.add(this);
		this.isChild = true;
		this.addMouseListener(this.game.dummyListener);
	}

	@Override
	public Boolean checkDeplacement(Card elem) {
		if (elem.isHidden() || this == game.dummies.get(0)) {
			return (false);
		}
		int index = game.dummies.indexOf(this);
		if (index > 7) {
			if (elem.value == 0)
				return (true);
		}
		else if (index > 0 && elem.value == 12)
			return (true);
		return (false);
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
	}
}