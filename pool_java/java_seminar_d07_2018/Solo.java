public class Solo<T> {
	private T value;
	public Solo(T value) {
		this.value = value;
	}
	public T getValue() {
		return (value);
	}
	public void setValue(T newValue) {
		this.value = newValue;
	}
}