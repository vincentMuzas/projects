package solitr;
import solitr.Solitr;

/**
 * Hello world!
 *
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
