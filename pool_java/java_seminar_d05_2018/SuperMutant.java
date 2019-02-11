public class SuperMutant extends Monster {
	private static int count = 1;
	public SuperMutant() {
		super("SuperMutant #" + count, 170, 20);
		count++;
		this.damage = 60;
		this.apcost = 20;
		System.out.println(this.getName() + ": Roaarrr!");
	}
	@Override
	public void recoverAP() {
		super.recoverAP();
		this.hp += 10;
		if (this.hp > 170)
			this.hp = 170;
	}
}