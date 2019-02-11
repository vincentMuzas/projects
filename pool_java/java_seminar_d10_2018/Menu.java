public abstract class Menu {
	protected Drink drink;
	protected Food meal;

	/**
	 * @return the drink
	 */
	public Drink getDrink() {
		return drink;
	}
	/**
	 * @return the meal
	 */
	public Food getMeal() {
		return meal;
	}
	public float getPrice() {
		return ((drink.getPrice() + meal.getPrice()) * 0.9);
	}
}