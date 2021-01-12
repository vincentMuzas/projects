package eu.epitech.trantor;

import java.io.IOException;

public class Main {
	public static void main(String[] args) {
		Server serv = null;
		Integer w = Integer.getInteger(getargs(args, "-w"));
		Integer h = Integer.getInteger(getargs(args, "-h"));
		Integer p = Integer.getInteger(getargs(args, "-p"));
		if (w == 0 || h == 0 || p == 0)
			return;
		// Init map + commands handler
		Map map = new Map(w, h);
		Commands commands = new Commands(map);
		
		try {
			serv = new Server(p);
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
		while (true) {
			serv.run(map, commands);
		}
	}
	public static String getargs(String[] args, String wich) {
		String res = null;
		for (Integer i = 0; i < args.length - 1; i++) {
			if (args[i] == wich) {
				res = args[i + 1];
			}
		}
		return (res);
	}
}