public abstract class Character implements Movable, Comparable {
	protected String name;
	protected int life = 50;
	protected int agility = 2;
	protected int strength = 2;
	protected int wit = 2;
	protected final String RPGClass;
	protected int capacity = 0;

	protected Character(String name, String RPGClass) {
		this.name = name;
		this.RPGClass = RPGClass;
	}
	protected Character(String name, String RPGClass, int capacity) {
		this.name = name;
		this.RPGClass = RPGClass;
		this.capacity = capacity;
	}

	public String getName() {
		return (this.name);
	}
	public String getRPGClass() {
		return (this.RPGClass);
	}
	public int getLife() {
		return (this.life);
	}
	public int getAgility() {
		return (this.agility);
	}
	public int getStrength() {
		return (this.strength);
	}
	public int getWit() {
		return (this.wit);
	}
	public void attack(String weapon) {
		System.out.println(this.name + ": Rrrrrrrrr....");
	}
	@Override
	public void moveBack() {
		System.out.println(this.name + ": moves back");
	}
	@Override
	public void moveForward() {
		System.out.println(this.name + ": moves forward");
	}
	@Override
	public void moveRight() {
		System.out.println(this.name + ": moves right");
	}
	@Override
	public void moveLeft() {
		System.out.println(this.name + ": moves left");
	}
	public final void unsheathe() {
		System.out.println(this.name + ": unsheathes his weapon.");
	}
	@Override
	public int compareTo(Character o) {
		int val1, val2;
		if (this instanceof Warrior)
			val1 = this.getStrength();
		else (this instanceof Mage)
			val1 = this.capacity;
		
	}
}