package solitr;

import java.awt.Color;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * Displayer
 */
public class Displayer extends JFrame {

	private static final long serialVersionUID = -6858273108646257540L;
	public JPanel content = new JPanel();
	public Displayer() {
		this.setTitle("solitaire");
		this.setSize(1280, 720);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setResizable(false);
		this.content.setBackground(Color.GREEN);

		this.setContentPane(this.content);
		this.getContentPane().setLayout(null);
	}
}