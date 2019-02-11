import java.util.ArrayList;
import java.util.List;

public class Elf {
	private Toy toy;
	private List<GiftPaper> papers;
	private Factory factory;
	public Elf(Factory factory) {
		papers = new ArrayList<>();
		this.factory = factory;
		this.toy = null;
	}
	public Boolean pickToy(String item) {
		if (toy != null) {
			System.out.println("Minute please ?! I'm not that fast.");
			return (false);
		}
		try {
			toy = factory.create(item);
		}
		catch (NoSuchToyException e){
			System.out.println("I didn't find any " + item + ".");
			return (false);
		}
		System.out.println("What a nice one! I would hava liked to keep it...");
		return (true);
	}
	public Boolean pickPapers(int n) {
		for (int i = 0; i < n; i++) {
			papers.add(new GiftPaper());
		}
		return true;
	}
	public GiftPaper pack() {
		if (papers.isEmpty()) {
			System.out.println("Wait... I can't pack it with my shirt.");
			return null;
		}
		GiftPaper local = papers.get(0);
		if (toy == null) {
			System.out.println("I don't hava any toy, but hey at least it's a paper!");
			papers.remove(0);
			return (local);
		}
		else {
			System.out.println("And an other kid will be happy!");
			papers.remove(0);
			local.wrap(toy);
			toy = null;
			return (local);
		}
	}
}