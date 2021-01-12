package eu.epitech.trantor;

import java.util.*;

/**
 * Case
 */
public class Case {

	//#region Properties
	
	private List<Item> items = new ArrayList<Item>();
	private List<Drone> drones = new ArrayList<Drone>();

	//#endregion

	//#region Constructor

	public Case() {
	}

	//#endregion

	//#region Methods

	/**
	 * Add item to case
	 * @param item to add
	 */
	public void addToItems(Item item) {
		this.items.add(item);
	}

	/**
	 * Remove item to case
	 * @param item to remove
	 * @return null if error else Item removed
	 */
	public Item removeItem(Item item) {
		Item itemToRemove = null;
		for (int i = 0; i < this.items.size(); i++) {
			if (this.items.get(i).getId() == item.getId()) {
				itemToRemove = this.items.get(i);
			}
		}
		if (itemToRemove != null) {
			this.items.remove(itemToRemove);
		}
		return itemToRemove;
	}

	/**
	 * Method to add drone at case
	 * @param drone to add
	 */
	public void addDrone(Drone drone) {
		this.drones.add(drone);
	}

	/**
	 * Method to remove drone to case
	 * @param drone to remove
	 */
	public void removeDrone(Drone drone) {
		this.drones.remove(drone);
	}

	/**
	 * @return the drones
	 */
	public List<Drone> getDrones() {
		return drones;
	}
	
	/**
	 * @param drones the drones to set
	 */
	public void setDrones(List<Drone> drones) {
		this.drones = drones;
	}

	@Override
	/**
	 * Case to string
	 */
	public String toString() {
		String result = new String();

		for (int i = 0; i < this.drones.size(); i++) {
			if (i != (this.drones.size() - 1) && i != 0) {
				result += " ";
			}
			result += "player";
		}
		
		for (int i = 0; i < this.items.size(); i++) {
			if (result.length() != 0 && i == 0) {
				result += " ";
			}
			result += this.items.get(i).getEntitled();
			if (i != (this.items.size() - 1)) {
				result += " ";
			}
		}
		return result;
	}

	//#endregion

}
