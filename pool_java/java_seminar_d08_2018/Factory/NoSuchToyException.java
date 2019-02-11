public class NoSuchToyException extends Exception {
	private static final long serialVersionUID = 69420322;
	public NoSuchToyException(String toy) {
		super("No such toy: " + toy + ".");
	}	
}