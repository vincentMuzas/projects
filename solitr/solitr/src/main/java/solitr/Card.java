package solitr;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.io.File;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

/**
 * Card
 */
public class Card extends JPanel {
	
	private static final long serialVersionUID = -2095872056034796873L;
	private int value;
	private int family;
	private int color;
	private String card_name;
	private BufferedImage image;
	private BufferedImage hiddenimage;
	private Boolean hidden;
	
	public Card (int value, int family, int color) {
		String[] value_name = {"ace", "2", "3", "4", "5", "6", "7", "8",
		"9", "10", "jack", "queen", "king"};
		String[] family_name = {"diamonds", "clubs", "hearts", "spades"};
		this.value = value;
		this.family = family;
		this.color = color;
		this.hidden = true;
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
		addMouseListener(listener);
		setVisible(true);
	}
	private MouseListener listener = new MouseAdapter() {
		public void mouseClicked(MouseEvent e) {
			System.out.println( ((Card) e.getComponent()).getCardName());
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

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		if (this.hidden)
			g.drawImage(hiddenimage, 0, 0, this);
		else
			g.drawImage(image, 0, 0, this);
	}

	/* getters */
	public String getCardName() {return (this.card_name);};
	public int getValue() {return (this.value); };
	public int getFamily() {return (this.family); };
	public int getColor() {return (this.color); };
	public BufferedImage getImage() {return (this.image); };
	public Boolean getHidden() {return (this.hidden); };


}