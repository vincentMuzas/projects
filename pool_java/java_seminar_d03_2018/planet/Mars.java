package planet;

public class Mars {
	private static int count = 0;
	private final int id;
	private String landingSite;
	public Mars(String landing) {
		landingSite = landing;
		id = count;
		count ++;
	}
	public int getId() {
		return (id);
	}
	public String getLandingSite() {
		return (landingSite);
	}
}