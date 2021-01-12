package eu.epitech.trantor;

import java.util.*;

/**
 * Map
 */
public class Map {

	//#region Properties

	private Case[][] map;
	private Integer sizeX = 0;
	private Integer sizeY = 0;
	private List<Item> items = new ArrayList<>();
	private Integer nbItem = 0;

    //#endregion

    //#region Constructor

	public Map(Integer sizeX, Integer sizeY) {
		this.sizeX = sizeX;
		this.sizeY = sizeY;
		this.map = new Case[this.sizeX][this.sizeY];
		for (int x = 0; x < sizeX; x++) {
			for (int y = 0; y < sizeY; y++) {
				this.map[x][y] = new Case();
			}
		}
		randomItem(150);
	}

    //#endregion

	//#region Methods

	/**
	 * @return the map
	 */
	public Case[][] getMap() {
		return this.map;
	}

	/**
	 * @return the sizeX
	 */
	public Integer getSizeX() {
		return this.sizeX;
	}

	/**
	 * @return the sizeY
	 */
	public Integer getSizeY() {
		return this.sizeY;
	}

	/**
	 * Method to refresh positions of drones
	 * @param drones to refresh
	 */
	public void refreshDrones(List<Drone> drones) {
		for (int x = 0; x < this.sizeX; x++) {
			for (int y = 0; y < this.sizeY; y++) {
				map[x][y].setDrones(new ArrayList<Drone>());
			}
		}

		for (Drone drone : drones) {
			map[drone.getPosX()][drone.getPosY()].addDrone(drone);
		}
	}

	/**
	 * Method to generate random item on map by nb
	 * @param nbItem of items to add on map
	 */
	public void randomItem(Integer nbItem) {
		for (int j = 0; j < nbItem; j++) {
			int id = (int)(Math.random() * 6);
			Item item = Item.generateItemById(id);
			Integer posX = (int)(Math.random() * this.sizeX);
			Integer posY = (int)(Math.random() * this.sizeY);
			Case caseToImplement = this.map[posX][posY];
			caseToImplement.addToItems(item);
		}
	}

	//#endregion
}
