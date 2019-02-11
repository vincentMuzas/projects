public class Gecko {
	private String name = "Unknown";
	public Gecko(String param) {
		name = param;
		System.out.println("Hello " + name + "!");
	}
	public Gecko() {
		System.out.println("Hello!");
	}
	public String getName() {
		return (name);
	}
}