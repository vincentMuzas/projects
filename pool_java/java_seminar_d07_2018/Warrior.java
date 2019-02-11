public class Warrior extends Character {
	public Warrior(String name) {
		super(name, "Warrior");
		this.life = 100;
		this.strength = 10;
		this.agility = 8;
		this.wit = 3;
		System.out.println(this.name + ": My name will go down in history!");
	}
	public Warrior(String name, int n) {
		super(name, "Warrior", n);
		this.life = 100;
		this.strength = n;
		this.agility = 8;
		this.wit = 3;
		System.out.println(this.name + ": My name will go down in history!");
	}
	public void attack(String weapon) {
		if (weapon == "hammer" || weapon == "sword") {
			super.attack(weapon);
			System.out.println(this.name + ": I'll crush you with my " + weapon + "!");
		}
	}
	@Override
	public void moveBack() {
		System.out.println(this.name + ": moves back like a bad boy.");
	}
	@Override
	public void moveForward() {
		System.out.println(this.name + ": moves forward like a bad boy.");
	}
	@Override
	public void moveRight() {
		System.out.println(this.name + ": moves right like a bad boy.");
	}
	@Override
	public void moveLeft() {
		System.out.println(this.name + ": moves left like a bad boy.");
	}
}