public class Mars {
	private static int count = 0;
	private final int id;
	public Mars() {
		id = count;
		count ++;
	}
	public int getId() {
		return (id);
	}
}