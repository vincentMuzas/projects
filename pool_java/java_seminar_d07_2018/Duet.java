public class Duet<T> {
	public static<T extends Comparable<T>> T min(T one, T two) {
		int res = one.compareTo(two);
		return (res < 0 ? one : two);
	}
	public static<T extends Comparable<T>> T max(T one, T two) {
		int res = one.compareTo(two);
		return (res > 0 ? one : two);
	}
}