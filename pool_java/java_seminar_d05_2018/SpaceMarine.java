import javax.lang.model.util.ElementScanner6;

abstract public class SpaceMarine extends Unit {
	private Weapon weapon = null;
	public SpaceMarine(String name, int hp, int ap) {
		super(name, hp, ap);
	}
	public Weapon getWeapon() {
		return weapon;
	}
	@Override
	public Boolean equip(Weapon thing) {
		if (this.weapon != null)
			return false;
		this.weapon = thing;
		System.out.println(this.getName() + " has been equipped with a " + this.weapon.getName() + ".");
		return true;
	}
	@Override
	public Boolean attack(Unit target) {
		if (this.getHp() <= 0 || target.getHp() <= 0)
			return false;
		else if (this.weapon == null) {
			System.out.println(this.getName() + ": Hey, this is crazy. I'm not going to fight this empty-handed.");
			return false;
		}
		else if (this.getWeapon().isMelee() && this.closeTo != target) {
			System.out.println(this.getName() + ": I'm too far away from " + target.getName() + ".");
			return false;
		}
		else if (this.getAp() - this.getWeapon().getApcost() < 0) {
			return false;
		}
		System.out.println(this.getName() + " attacks " + target.getName() + " with a " + this.getWeapon().getName() + ".");
		this.getWeapon().attack();
		target.recieveDamage(this.getWeapon().damage());
		return true;
	}
	@Override
	public void recoverAP() {
		this.ap += 9;
		if (this.ap > 50)
			this.ap = 50;
	}
}