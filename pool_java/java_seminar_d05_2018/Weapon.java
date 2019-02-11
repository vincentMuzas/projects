abstract public class Weapon {
	protected String name;
	protected int apcost;
	protected int damage;
	protected Boolean mele;
	protected Weapon(String name, int apcost, int damage, Boolean mele) {
		this.name = name;
		this.apcost = apcost;
		this.damage = damage;
		this.mele = mele;
	}
	public String getName() {
		return (name);
	}
	public int getApcost() {
		return (apcost);
	}
	public int damage() {
		return (damage);
	}
	public Boolean isMelee() {
		return (mele);
	}
	public void attack() {
		return;
	}
}