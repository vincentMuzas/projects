public abstract class Bread implements Food {
	protected float price;
	protected int calories;
	protected int bakingTime = 0;

	public Bread(float price, int calories) {
		this.price = price;
		this.calories = calories;
	}
	@Override
	public float getPrice() {
		return price;
	}
	@Override
	public int getCalories() {
		return calories;
	}
	public int getBakingTime() {
		return bakingTime;
	}
}