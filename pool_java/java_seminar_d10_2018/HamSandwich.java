public class HamSandwich extends Sandwich {
	public HamSandwich() {
		super((float) 4.00 , 230);
		this.vegetarian = false;
		this.ingredients.add("tomato");
		this.ingredients.add("salad");
		this.ingredients.add("cheese");
		this.ingredients.add("ham");
		this.ingredients.add("butter");
	}
}