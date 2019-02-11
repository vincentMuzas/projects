public class GreatWhite extends Shark {
	public GreatWhite(String name) {
		super(name);
	}
	public Boolean canEat(Animal ayaya) {
		if (ayaya instanceof Canary || !super.canEat(ayaya))
			return (false);
		else
			return (true);
	}
	public Boolean eat(Animal ayaya) {
		if (ayaya instanceof Canary) {
			System.out.println(this.getName() + ": Next time you try to give me that to eat I'll eat you instand.");
			return (false);
		}
		else if (ayaya instanceof Shark && ayaya != this) {
			System.out.println(this.getName() + ": The best meal one coud wish for");
			return (true);
		}
		else if (!this.canEat(ayaya)) {
			System.out.println(this.getName() + ": It's not worth my time.");
			return (false);
		}
		else {
			System.out.println(this.getName() + ": ate a " + ayaya.getType() + " named " + ayaya.getName() + ".");
			this.frenzy = false;
			return (true);
		}
	}
}