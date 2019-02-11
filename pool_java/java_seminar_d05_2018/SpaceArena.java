import java.util.ArrayList;

public class SpaceArena {
	ArrayList<Monster> monsterlist;
	ArrayList<SpaceMarine> marinelist;

	private static SpaceMarine marine = null;
	private static Monster monster = null;
	public SpaceArena() {
		monsterlist = new ArrayList<Monster>();
		marinelist = new ArrayList<SpaceMarine>();
	}
	public void enlistMonsters(java.util.List<Monster> list) {
		int index = 0;
		while (index < list.size()) {
			monsterlist.add(list.get(index));
			index++;
		}
	}
	public void enlistSpaceMarines(java.util.List<SpaceMarine> list) {
		int index = 0;
		while (index < list.size()) {
			marinelist.add(list.get(index));
			index++;
		}
	}
	public Boolean fight() {
		Boolean fail = false;
		Boolean attackresult;
		Boolean round = false;
		if (monsterlist.isEmpty()) {
			System.out.println("No monsters avilable to fight.");
			fail = true;
		}
		if (marinelist.isEmpty()) {
			System.out.println("Those cowards ran away");
			fail = true;
		}
		if (fail == true)
			return false;
		while (monsterlist.isEmpty() == false && 
				marinelist.isEmpty() == false) {
			round = true;
			if (marine != marinelist.get(0)) {
				marine = marinelist.get(0);
				System.out.println(marine.getName() + " has entered the arena.");
			}
			if (monster != monsterlist.get(0)) {
				monster = monsterlist.get(0);
				System.out.println(monster.getName() + " has entered the arena.");
			}
			attackresult = marine.attack(monster);
			if (attackresult == false && marine.getAp() - marine.getWeapon().getApcost() < 0) {
				marine.recoverAP();
			}
			else if (attackresult == false) {
				marine.moveCloseTo(monster);
			}
			if (monster.getHp() <= 0) {
				monsterlist.remove(monster);
				marine.recoverAP();
				continue;
			}
			attackresult = monster.attack(marine);
			if (attackresult == false && monster.getAp() - monster.apcost < 0) {
				monster.recoverAP();
			}
			else if (attackresult == false) {
				monster.moveCloseTo(marine);
			}
			if (marine.getHp() <= 0) {
				marinelist.remove(marine);
				monster.recoverAP();
				continue;
			}
		}
		if (monsterlist.isEmpty()) {
			System.out.println("The spaceMarines are victorious.");
		}
		else if (marinelist.isEmpty()) {
			System.out.println("The monsters are victorious.");
		}
		return (round);
	}
}