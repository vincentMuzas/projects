import java.util.concurrent.atomic.AtomicInteger;
import java.util.ArrayList;

public class Animal {
	enum Type {
		MAMMAL,
		FISH,
		BIRD;
	}
	private static final AtomicInteger numberOfAnimals = new AtomicInteger();
	private static int numberOfMammals = 0;
	private static int numberOfFish = 0;
	private static int numberOfBirds = 0;
	private Type type;
	private int legs;
	private String name;
	protected Animal(String name, int legs, Type type) {
		numberOfAnimals.addAndGet(1);
		this.type = type;
		this.name = name;
		this.legs = legs;
		switch (type) {
			case MAMMAL:
				numberOfMammals ++;
				break;
			case FISH:
				numberOfFish ++;
				break;
			case BIRD:
				numberOfBirds ++;
				break;
		}
		System.out.println("My name is " + name + " and I am a " + this.getType() + "!");
	}
	public String getType() {
		return (type.name().toLowerCase());
	}
	public int getLegs() {
		return (legs);
	}
	public String getName() {
		return (name);
	}
	public static int getNumberOfAnimals() {
		System.out.println("There " + ((numberOfAnimals.get() < 2) ? "is" : "are")
		+ " currently " + numberOfAnimals.get() + " animal" + 
		((numberOfAnimals.get() < 2) ? "" : "s") + " in our world");
		return (numberOfAnimals.get());
	}
	public static int getNumberOfMammals() {
		System.out.println("There " + ((numberOfMammals < 2) ? "is" : "are")
		+ " currently " + numberOfMammals + " mammal" +  ((numberOfMammals < 2) ? "" : "s")
		+ " in our world");
		return (numberOfAnimals.get());
	}
	public static int getNumberOfFish() {
		System.out.println("There " + ((numberOfFish < 2) ? "is" : "are")
		+ " currently " + numberOfFish + " fish" + " in our world");
		return (numberOfAnimals.get());
	}
	public static int getNumberOfBirds() {
		System.out.println("There " + ((numberOfBirds < 2) ? "is" : "are")
		+ " currently " + numberOfBirds + " bird" + ((numberOfBirds < 2) ? "" : "s") 
		+ " in our world");
		return (numberOfAnimals.get());
	}

}