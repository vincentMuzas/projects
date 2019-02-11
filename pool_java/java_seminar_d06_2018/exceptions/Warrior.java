public class Warrior extends Character {
	public Warrior(String name) {
		super(name, "Warrior");
		this.life = 100;
		this.strength = 10;
		this.agility = 8;
		this.wit = 3;
		System.out.println(this.name + ": My name will go down in history!");
	}
	public void attack(String weapon) throws WeaponException {
		if (weapon == null || weapon.isEmpty()) {
			throw new WeaponException(this.name + ": I refuse to fight with my bare hands.");
		}
		else if (weapon == "hammer" || weapon == "sword") {
			super.attack(weapon);
			System.out.println(this.name + ": I'll crush you with my " + weapon + "!");
		}
		else {
			throw new WeaponException(this.name + ": A " + weapon + "?? What should I do with this?!");
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