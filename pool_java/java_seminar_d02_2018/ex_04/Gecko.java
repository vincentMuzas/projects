public class Gecko {
	private String name = "Unknown";
	private int age = -1;
	public Gecko(String param, int age_param) {
		name = param;
		age = age_param;
		System.out.println("Hello " + name + "!");
	}
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
	public int getAge() {
		return (age);
	}
	public void setAge(int param) {
		age = param;
	}
	public void status() {
		String result;
		switch (age) {
			case 0:
				result = "Unborn Gecko";
				break;
			case 1: case 2:
				result = "Baby Gecko";
				break;
			case 3: case 4: case 5: case 6: case 7: case 8: case 9:
				result = "Adult Gecko";
				break;
			case 11: case 12: case 13:
				result = "Old Gecko";
				break;
			default:
				result = "Impossible Gecko";
		}
		System.out.println(result);
	}
}