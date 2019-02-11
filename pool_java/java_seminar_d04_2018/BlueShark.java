public class BlueShark extends Shark {
	public BlueShark(String name) {
		super(name);
	}
	public Boolean canEat(Animal ayaya) {
		if (ayaya.getType() == "fish" || !super.canEat(ayaya))
			return (false);
		else
			return (true);
	}
}