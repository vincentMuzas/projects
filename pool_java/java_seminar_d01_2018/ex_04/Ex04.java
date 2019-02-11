class Ex04 {
	public static void main(String[] args) {
		printMovieFromNbr(3);
		printMovieFromNbr(6);
		printMovieFromNbr(23);
		printMovieFromNbr(28);
		printMovieFromNbr(42);
	}
	public static void printMovieFromNbr(int nbr) {
		switch (nbr) {
			case 3:
				System.out.println("The Three Brothers");
				break;
			case 6:
				System.out.println("The Sixth Sense");
				break;
			case 23:
				System.out.println("The Number 23");
				break;
			case 28:
				System.out.println("28 Days Later");
				break;
			default:
				System.out.println("I dont know");
		}
	}
}