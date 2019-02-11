import java.util.List;
import java.util.ArrayList;
public class Factory {
	public Toy create(String item) throws NoSuchToyException {
		if (item == "teddy") {
			return (new TeddyBear());
		}
		else if (item == "game-boy") {
			return (new Gameboy());
		}
		throw new NoSuchToyException(item);
	}
	public List<GiftPaper> getPapers(int n) {
		List<GiftPaper> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			list.add(new GiftPaper());
		}
		return (list);
	}
}