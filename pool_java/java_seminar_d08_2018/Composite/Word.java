public class Word implements Sentence {
	private String param;
	public Word() {
		param = "word";
	}
	public Word(String param) {
		this.param = param;
	}
	@Override
	public void print() {
		System.out.println(this.param);
	}
}