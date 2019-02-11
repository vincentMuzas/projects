import java.util.ArrayList;
import java.util.List;

public class Battalion {
	private List<Character> furioso_melodia;
	public Battalion() {
		furioso_melodia = new ArrayList<Character>();
	}
	public void add(List<? extends Character> new_units) {
		for (int i = 0; i < new_units.size(); i++) {
			furioso_melodia.add(new_units.get(i));
		}
	}
	public void display() {
		for (int i = 0; i < furioso_melodia.size(); i++) {
			System.out.println(furioso_melodia.get(i).getName());
		}
	}
}