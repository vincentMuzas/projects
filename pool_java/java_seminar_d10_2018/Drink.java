public abstract class Drink implements Food {
	protected float price;
	protected int calories;
	protected Boolean aCan = false;

	public Drink(float price, int calories) {
		this.price = price;
		this.calories = calories;
	}
	@Override
	public int getCalories() {
		return calories;
	}
	@Override
	public float getPrice() {
		return price;
	}
	public Boolean isACan() {
		return aCan;
	}
}