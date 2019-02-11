import javax.lang.model.util.ElementScanner6;

public class RadScorpion extends Monster {
	private static int count = 1;
	public RadScorpion() {
		super("RadScorpion #" + count, 80, 50);
		count ++;
		this.damage = 25;
		this.apcost = 8;
		System.out.println(this.getName() + ": Crrr!");
	}
	@Override
	public Boolean attack(Unit target) {
		if (this.getHp() < 0)
			return false;
		if (this.closeTo != target) {
			System.out.println(this.getName() + ": I'm too far away from " + target.getName() + ".");
			return (false);
		}
		if (this.getAp() - this.apcost >= 0) {
			this.ap -= this.apcost;
			System.out.println(this.getName() + " attacks " + target.getName());
			if (target instanceof AssaultTerminator)
				target.recieveDamage(this.getDamage());
			else if (target instanceof SpaceMarine)
				target.recieveDamage(this.getDamage() * 2);
			else
				target.recieveDamage(this.getDamage());
			return true;
		}
		return false;
	}
}