public class TacticalMarine extends SpaceMarine {
	public TacticalMarine(String name) {
		super(name, 100, 20);
		System.out.println(name + " on duty.");
		PlasmaRifle weapon = new PlasmaRifle();
		this.equip(weapon);
	}
	@Override
	public void recoverAP() {
		this.ap += 9;
		if (this.ap > 50)
			this.ap = 50;
	}
}