public class Shark extends Animal {
	public Shark(String name) {
		super(name, 0, Animal.Type.FISH);
		System.out.println("A KILLER IS BORN!");
	}
	protected Boolean frenzy = false;
	public void smellBlood(Boolean status) {
		frenzy = status;
	}
	public Boolean status() {
		if (this.frenzy)
			System.out.println(this.getName() + " is smelling blood and wants to kill.");
		else
			System.out.println(this.getName() + " is swimming peacefully");
		return (this.frenzy);
	}
	public Boolean canEat(Animal ayaya) {
		if (ayaya == this || this.frenzy == false)
			return (false);
		else
			return (true);
	}
	public Boolean eat(Animal ayaya) {
		if (!this.canEat(ayaya)) {
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