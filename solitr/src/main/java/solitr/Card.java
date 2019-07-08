package solitr;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.ArrayList;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

/**
 * Card
 */
public class Card extends JPanel {
	
	private static final long serialVersionUID = -2095872056034796873L;
	protected int value;
	protected int family;
	protected int color;
	protected String card_name;
	protected BufferedImage image;
	protected BufferedImage hiddenimage;
	protected Boolean hidden;
	public Boolean isChild;
	protected Solitr game;
	
	public Card (int value, int family, int color, Solitr ptr) {
		game = ptr;
		String[] value_name = {"ace", "2", "3", "4", "5", "6", "7", "8",
		"9", "10", "jack", "queen", "king"};
		String[] family_name = {"diamonds", "clubs", "hearts", "spades"};
		this.value = value;
		this.family = family;
		this.color = color;
		this.hidden = true;
		this.isChild = false;
		this.card_name = value_name[value] + "_of_" + family_name[family] + ".png";
		try {
			this.image = ImageIO.read(new File("PNG-cards-1.3/" + this.card_name));
			this.hiddenimage = ImageIO.read(new File("PNG-cards-1.3/BackCard.png"));
		}
		catch (Exception e) {
			System.out.println(e.getMessage());
			System.exit(84);
		}
		this.image = resize(image, 100, 142);
		this.hiddenimage = resize(hiddenimage, 100, 142);
		this.setPosition(0, 0);
		//addMouseListener(listener);
		setVisible(true);
	}
	public MouseListener listener = new MouseAdapter() {
		public void mouseClicked(MouseEvent e) {
			System.out.println( ((Card) e.getComponent()).getCardName());
			game.refreshDisplay();
		}
	};

	public static BufferedImage resize(BufferedImage img, int newW, int newH) { 
		Image tmp = img.getScaledInstance(newW, newH, Image.SCALE_SMOOTH);
		BufferedImage dimg = new BufferedImage(newW, newH, BufferedImage.TYPE_INT_ARGB);
	    
		Graphics2D g2d = dimg.createGraphics();
		g2d.drawImage(tmp, 0, 0, null);
		g2d.dispose();
	    
		return dimg;
	}


	public void setHidden(Boolean state) {
		this.hidden = state;
	}

	public void setPosition(int column, int row) {
		if (row == 0)
			this.setBounds(10 + column * 120, 10, 100, 142);
		else
			this.setBounds(10 + column * 120, 150 + 35*row, 100, 142);
	}

	public Boolean checkDeplacement(Card elem) {
		if (elem.isHidden())
			return (false);
		ArrayList<ArrayList<Card>> piles = new ArrayList<>();
		piles.add (game.pile1);piles.add (game.pile2);
		piles.add (game.pile3);piles.add (game.pile4);
		for (int i = 0; i < piles.size(); i++) {
			if (piles.get(i).contains(this) &&
			elem.value == this.value + 1 && elem.family == this.family)
				return (true);
		}
		if (elem.value != this.value - 1 || elem.color == this.color) {
			return (false);
		}
		return (true);
	}

	public Boolean isHidden() {
		return (this.hidden);
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		if (!isChild) {
			if (this.hidden)
				g.drawImage(hiddenimage, 0, 0, this);
			else
				g.drawImage(image, 0, 0, this);
		}
	}

	/* getters */
	public String getCardName() {return (this.card_name);};
	public int getValue() {return (this.value); };
	public int getFamily() {return (this.family); };
	public int getColor() {return (this.color); };
	public BufferedImage getImage() {return (this.image); };
	public Boolean getHidden() {return (this.hidden); };


}