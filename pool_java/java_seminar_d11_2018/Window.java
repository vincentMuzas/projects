import java.awt.Dimension;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;

public class Window extends JFrame {
	public static final long serialVersionUID = 69;
	private ArrayList<JButton> buttons;
	private ArrayList<JPanel> panels; 
	public Window(String title,  int width, int height) {
		super();
		this.setTitle(title);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(new Dimension(width, height));
		this.setLayout(null);
		buttons = new ArrayList<>();
		panels = new ArrayList<>();
		buttons.add(new JButton("1"));
		buttons.add(new JButton("2"));
		buttons.add(new JButton("3"));
		buttons.add(new JButton("+"));
		buttons.add(new JButton("4"));
		buttons.add(new JButton("5"));
		buttons.add(new JButton("6"));
		buttons.add(new JButton("-"));
		buttons.add(new JButton("7"));
		buttons.add(new JButton("8"));
		buttons.add(new JButton("9"));
		buttons.add(new JButton("/"));
		buttons.add(new JButton("0"));

		int x = 0;
		int y = 0;
		for (int i = 0; i < buttons.size(); i++) {
			buttons.get(i).setBounds(x, y, 45, 35);
			panels.add(new JPanel());
			panels.get(i).setBounds(x, y, 45, 35);
			panels.get(i).add(buttons.get(i));
			this.getContentPane().add(panels.get(i));
			x += 45;
			if ((i + 1) % 4 == 0) {
				x = 0;
				y += 35;
			}
		}
		this.setVisible(true);
	}
	public static void main(String[] args) {
		new Window("bonjour", 200, 200);
	}
}