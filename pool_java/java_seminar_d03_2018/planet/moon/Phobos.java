package planet.moon;

public class Phobos {
	private planet.Mars planet;
	private String landingSite;
	public Phobos()
	{
		System.out.println("No planet given.");
	}
	public Phobos(planet.Mars planet, String landingSite) {
		this.planet = planet;
		this.landingSite = landingSite;
		System.out.println("Phobos placed in orbit.");
	}
	public planet.Mars getMars() {
		return planet;
	}
	public String getLandingSite() {
		return landingSite;
	}
}