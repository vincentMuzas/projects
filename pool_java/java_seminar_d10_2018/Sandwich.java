import java.util.ArrayList;
import java.util.List;

public abstract class Sandwich implements Food {
	protected float price;
	protected int calories;
	protected Boolean vegetarian = false;
	protected List<String> ingredients;

	public Sandwich(float price, int calories) {
		this.price = price;
		this.calories = calories;
		this.ingredients = new ArrayList<>();
	}
	@Override
	public int getCalories() {
		return calories;
	}
	@Override
	public float getPrice() {
		return price;
	}
	public Boolean isVegetarian() {
		return vegetarian;
	}
	/**
	 * @return the ingredients
	 */
	public List<String> getIngredients() {
		return ingredients;
	}
}