public interface Fighter {
	public Boolean equip(Weapon thing);
	public Boolean attack(Unit value);
	public void recieveDamage(int value);
	public Boolean moveCloseTo(Unit unit);
	public void recoverAP();
	public String getName();
	public int getAp();
	public int getHp();
}
