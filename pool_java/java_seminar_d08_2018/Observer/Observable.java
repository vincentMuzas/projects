public abstract interface Observable {
	public void addObserver(Observer e);
	public Boolean notifyObservers();
}