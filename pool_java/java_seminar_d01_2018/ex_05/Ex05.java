import java.util.ArrayList;

class Ex05 {
	public static ArrayList<String> myGetArgs(String... var) {
		ArrayList<String> arr = new ArrayList<String>();
		for (String s : var)
			arr.add(s);
		return (arr);
	}
}