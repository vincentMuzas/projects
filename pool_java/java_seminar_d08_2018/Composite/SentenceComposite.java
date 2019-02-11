import java.util.ArrayList;
import java.util.List;

public class SentenceComposite implements Sentence {
	public final List<Word> childSentence;
	public SentenceComposite() {
		childSentence = new ArrayList<>();
	}
	public void add(Sentence e) {
		if (e instanceof Word) {
			childSentence.add((Word) e);
		}
		else if (e instanceof SentenceComposite) {
			SentenceComposite loc = (SentenceComposite) e;
			for (int i = 0; i < loc.childSentence.size(); i++) {
				this.add(loc.childSentence.get(i));
			}
		}
	}
	public void remove(Sentence e) {
		if (e instanceof Word)
			childSentence.remove((Word) e);
		else if (e instanceof SentenceComposite) {
			SentenceComposite loc = (SentenceComposite) e;
			for (int i = 0; i < loc.childSentence.size(); i = 0) {
				this.remove(loc.childSentence.get(0));
			}
		}
	}
	@Override
	public void print() {
		for (int i = 0; i < childSentence.size(); i++) {
			childSentence.get(i).print();
		}
	}
}