import java.util.ArrayList;

import javax.lang.model.util.ElementScanner6;

public class Team {
	private ArrayList<Astronaut> squad;
	private String name;
	public Team(String name)
	{
		this.name = name;
		this.squad = new ArrayList<Astronaut>();
	}
	public void add(Astronaut who) {
		squad.add(who);
	}
	public void remove(Astronaut who) {
		squad.remove(who);
	}
	public int countMembers() {
		return (squad.size());
	}
	public void showMembers() {
		System.out.print(name + ": ");
		for (int i = 0; i < squad.size(); i++) {
			System.out.print(squad.get(i).getName());
			if (squad.get(i).getDestination() != null)
				System.out.print(" on mission");
			else
				System.out.print(" on standby");
			if (i < squad.size() - 1)
				System.out.print(", ");
		}
		System.out.println('.');
	}
	public void doActions() {
		System.out.println(name + ": Nothing to do.");
	}
	public void doActions(Object action) {
		for (int i = 0; i < squad.size(); i++) {
			if (action instanceof planet.Mars)
				squad.get(i).doActions((planet.Mars) action);
			if (action instanceof chocolate.Mars)
				squad.get(i).doActions((chocolate.Mars) action);
		}
	}
}