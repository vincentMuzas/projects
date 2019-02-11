public class Astronaut {
	private String name;
	private int snacks = 0;
	private String destination;
	private static int count = 0;
	private int id;
	public Astronaut(String name) {
		this.name = name;
		snacks = 0;
		id = count;
		count++;
		System.out.println(name + " ready for launch!");
	}
	public String getName() {
		return (name);
	}
	public int getSnacks() {
		return (snacks);
	}
	public String getDestination() {
		return (destination);
	}
	public int getId() {
		return (id);
	}
	public void doActions() {
		System.out.println(name + ": Nothing to do.");
		if (destination == null)
			System.out.println(name + ": I may have done nothing, but at least I have " + snacks + " Mars to eat at least!");
	}
	public void doActions(planet.Mars planet) {
		System.out.println(name + ": Started a mission!");
		destination = planet.getLandingSite();
		if (destination == null)
			System.out.println(name + ": I may have done nothing, but I have " + snacks + " Mars to eat at least!");
	}
	public void doActions(chocolate.Mars chocolate) {
		System.out.println(name + ": Thanks for this mars number " + chocolate.getId());
		if (destination == null)
			System.out.println(name + ": I may have done nothing, but at least I have " + snacks + " Mars to eat at least!");
		snacks ++;
	}
}