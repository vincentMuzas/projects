abstract class Unit implements Fighter {
	protected String name;
	protected int hp;
	protected int ap;
	protected Unit closeTo;
	protected Unit(String name, int hp, int ap) {
		this.name = name;
		this.hp = hp;
		this.ap = ap;
	}
	@Override
	public String getName() {
		return this.name;
	}
	@Override
	public int getHp() {
		return this.hp;
	}
	@Override
	public int getAp() {
		return this.ap;
	}
	@Override
	public void recieveDamage(int value) {
		this.hp -= value;
	}
	@Override
	public Boolean moveCloseTo(Unit unit) {
		if (closeTo == unit) {
			return false;
		}
		if (unit.getHp() > 0 && this.getHp() > 0) {
			System.out.println(this.getName() + " is moving closer to " + unit.getName() + ".");
			closeTo = unit;
			return true;
		}
		return false;
	}
	@Override
	public void recoverAP() {
		this.ap += 7;
		if (this.ap > 50)
			this.ap = 50;
	}
}