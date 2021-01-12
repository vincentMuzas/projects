package eu.epitech.trantor;

/**
 * Drone
 */
public class Drone {

	// #region Properties

	private java.util.Map<Integer, Integer> inventory = new java.util.HashMap<Integer, Integer>();
	private Integer posX;
	private Integer posY;
	private Integer orientation = 1;
	private Integer level = 1;
	private Integer id = 0;
	private Team team;

	// #endregion

	// #region Constructor

	public Drone(Integer id, Integer posX, Integer posY, Integer orientation, Integer level, Team team) {
		this.id = id;
		this.posX = posX;
		this.posY = posY;
		this.orientation = orientation;
		this.level = level;
		this.initInventory();
		this.team = team;

		final Drone drone = this;
		java.util.Timer timer = new java.util.Timer();
        timer.schedule(new java.util.TimerTask() {
            @Override
            public void run() {
                drone.removeToInventory(Item.generateItemById(0));
            }
		}, 126000, 126000);
	}

	// #endregion

	// #region Methods

	public void initInventory() {
		this.inventory.put(Item.generateItemById(0).getId(), 10);
		this.inventory.put(Item.generateItemById(1).getId(), 0);
		this.inventory.put(Item.generateItemById(2).getId(), 0);
		this.inventory.put(Item.generateItemById(3).getId(), 0);
		this.inventory.put(Item.generateItemById(4).getId(), 0);
		this.inventory.put(Item.generateItemById(5).getId(), 0);
		this.inventory.put(Item.generateItemById(6).getId(), 0);
	}

	/**
	 * Add item to inventory
	 * 
	 * @param item to add
	 */
	public void addToInventory(Item item) {
		this.inventory.put(item.getId(), this.inventory.getOrDefault(item.getId(), 0) + 1);
	}

	/**
	 * Remove item to inventory
	 * 
	 * @param item to remove
	 * @return 1 : OK; 0 : KO
	 */
	public boolean removeToInventory(Item item) {
		if (this.inventory.getOrDefault(item.getId(), 0) > 0) {
			this.inventory.put(item.getId(), this.inventory.getOrDefault(item.getId(), 0) - 1);
			return true;
		} else {
			return false;
		}
	}

	/**
	 * Remove item to inventory with nb
	 * 
	 * @param item to remove
	 * @return 1 : OK; 0 : KO
	 */
	public boolean removeToInventory(Item item, Integer nb) {
		if (this.inventory.getOrDefault(item.getId(), 0) >= nb) {
			this.inventory.put(item.getId(), this.inventory.getOrDefault(item.getId(), 0) - nb);
			return true;
		} else {
			return false;
		}
	}

	/**
	 * Method to count each occurences of an item in inventory
	 * 
	 * @param item
	 * @return 0 : If no item else number of occurences
	 */
	public Integer countItem(Item item) {
		return this.inventory.getOrDefault(item.getId(), 0);
	}

	/**
	 * @param inventory the inventory to set
	 */
	public void setInventory(java.util.Map<Integer, Integer> inventory) {
		this.inventory = inventory;
	}

	/**
	 * @param orientation the orientation to set
	 */
	public void setOrientation(Integer orientation) {
		this.orientation = orientation;
	}

	/**
	 * @param posX the posX to set
	 */
	public void setPosX(Integer posX) {
		this.posX = posX;
	}

	/**
	 * @param posY the posY to set
	 */
	public void setPosY(Integer posY) {
		this.posY = posY;
	}

	/**
	 * @param level the level to set
	 */
	public void setLevel(Integer level) {
		this.level = level;
	}

	/**
	 * @return the inventory
	 */
	public java.util.Map<Integer, Integer> getInventory() {
		return inventory;
	}

	/**
	 * @return the id
	 */
	public Integer getId() {
		return id;
	}

	/**
	 * @return the orientation
	 */
	public Integer getOrientation() {
		return orientation;
	}

	/**
	 * @return the posX
	 */
	public Integer getPosX() {
		return posX;
	}

	/**
	 * @return the posY
	 */
	public Integer getPosY() {
		return posY;
	}

	/**
	 * @return the level
	 */
	public Integer getLevel() {
		return level;
	}

	/**
	 * @return the team
	 */
	public Team getTeam() {
		return team;
	}

	// #endregion

}
