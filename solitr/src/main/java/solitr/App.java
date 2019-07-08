package solitr;
import solitr.Solitr;

/**
 * A badly coded Solitaire game
 */
public class App 
{
    public static void main( String[] args )
    {
	try {
		new Solitr();
		
	} catch (Exception e) {
		System.out.println(e.getMessage());
		throw(e);
	}
    }
}
