public class AssaultTerminator extends SpaceMarine {
	public AssaultTerminator(String name) {
		super(name, 150, 30);
		System.out.println(name + " has teleported from space.");
		PowerFist weapon = new PowerFist();
		this.equip(weapon);
	}
	@Override
	public void recieveDamage(int value) {
		super.recieveDamage(Math.max(value - 3, 1));
	}
}