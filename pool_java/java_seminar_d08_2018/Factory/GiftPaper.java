public class GiftPaper {
	private Toy gift;

	public GiftPaper() {
		gift = null;
	}

	public void wrap(Toy gift) {
		this.gift = gift;
	}
	public Toy unwrap() {
		gift = null;
		return gift;
	}
}