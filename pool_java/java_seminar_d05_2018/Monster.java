abstract public class Monster extends Unit {
	protected int damage = 0;
	protected int apcost = 0;
	public Monster(String name, int hp, int ap) {
		super(name, hp, ap);
	}
	public int getDamage() {
		return damage;
	}
	public int getApcost() {
		return apcost;
	}
	public Boolean equip(Weapon thing) {
		System.out.println("Monsters are pround and fight with their own bodies.");
		return true;
	}
	public Boolean attack(Unit target) {
		if (this.getHp() <= 0 || target.getHp() <= 0)
			return false;
		if (this.closeTo != target) {
			System.out.println(this.getName() + ": I'm too far away from " + target.getName() + ".");
			return (false);
		}
		if (this.getAp() - this.apcost >= 0) {
			this.ap -= this.apcost;
			System.out.println(this.getName() + " attacks " + target.getName());
			target.recieveDamage(this.damage);
			return true;
		}
		return false;
	}
}