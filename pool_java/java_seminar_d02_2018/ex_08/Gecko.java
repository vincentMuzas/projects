public class Gecko {
	private String name = "Unknown";
	private int age = -1;
	private int energy = 100;
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
	public void hello(String arg) {
		System.out.println("Hello " + arg + ", I\'m " + name + "!");
	}
	public void hello(int nb) {
		for (int i = 0; i < nb; i++) {
			System.out.println("Hello, I\'m " + name + "!");
		}
	}
	public void eat(String thing) {
		thing = thing.toLowerCase();
		String result;
		switch (thing) {
			case "meat":
				energy = Math.min(energy + 10, 100);
				result = "Yummy !";
				break;
			case "vegetable":
				energy = Math.max (energy - 10, 0);
				result = "Erk !";
				break;
			default:
				result = "I can't eat this";
		}
		System.out.println(result);
	}
	public int getEnergy() {
		return (energy);
	}
	public void setEnergy(int value) {
		if (value <= 100 && value >= 0)
			energy = value;
	}
	public void work() {
		if (energy >= 25) {
			System.out.println("I'm working T.T");
			energy -= 9;
		} else {
			System.out.println("Heyyy I'm too sleepy, better take a nap!");
			energy += 50;
		}
	}
	public void fraternize(Gecko friend) {
		int validator;
		if (drink(friend)) {
			if (friend.drink(this)) {
				this.say("I'm going to drink with " + friend.getName() + "!");
				friend.say("I'm going to drink with " + name + "!");
				this.setEnergy(energy - 30);
				friend.setEnergy(friend.getEnergy() - 30);
			} else {
				friend.say("Sorry " + name + ", I'm too tired to go out tonight.");
				this.say("Oh! That's too bad, another time then!");
				return;
			}
		} else {
			if (friend.drink(this)) {
				this.say("Sorry " + friend.getName() + ", I'm too tired to go out tonight.");
				friend.say("Oh! That's too bad, another time then!");
			}
			else {
				this.say("Not today!");
				friend.say("Not today!");
			}
		}
	}
	public void fraternize(Snake friend) {
		if (energy >= 10) {
			this.say("LET'S RUN AWAY!!!");
			energy = 0;
		} else {
			System.out.println("...");
		}
	}
	public boolean drink(Gecko with) {
		if (energy > 30) {
			return (true);
		} else {
			return (false);
		}
	}
	public void say(String what) {
		System.out.println(what);
	}
}