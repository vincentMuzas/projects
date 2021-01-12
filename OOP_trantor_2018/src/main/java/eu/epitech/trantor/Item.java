package eu.epitech.trantor;

/**
 * Item
 */
public class Item {

    //#region Properties

    private int id;
    private String entitled;

    //#endregion

    //#region Constructor

    public Item(int id, String entitled) {
        this.id = id;
        this.entitled = entitled;
    }

    //#endregion

    //#region Methods

    /**
     * @return the id
     */
    public int getId() {
        return id;
    }

    /**
     * @return the entitled
     */
    public String getEntitled() {
        return entitled;
    }

    private void initItemList() {
        
    }

    /**
     * Method to generate item by id
     * @param id to create item
     * @return item generated
     */
    public static Item generateItemById(Integer id) {
        java.util.Map<Integer, String> mapItem = new java.util.HashMap<Integer, String>();
        mapItem.put(0, "food");
        mapItem.put(1, "linemate");
        mapItem.put(2, "deraumere");
        mapItem.put(3, "sibur");
        mapItem.put(4, "mendiane");
        mapItem.put(5, "phiras");
        mapItem.put(6, "thystame");
        String entitled = mapItem.getOrDefault(id, null);
        if (entitled == null) {
            return null;
        }
        return new Item(id, entitled);
    }

    /**
     * Method to generate item by string 
     * @param name to generate item
     * @return item generated
     */
    public static Item generateItemByString(String name) {
        java.util.Map<String, Integer> mapItem = new java.util.HashMap<String, Integer>();
        mapItem.put("food", 0);
        mapItem.put("linemate", 1);
        mapItem.put("deraumere", 2);
        mapItem.put("sibur", 3);
        mapItem.put("mendiane", 4);
        mapItem.put("phiras", 5);
        mapItem.put("thystame", 6);
        Integer id = mapItem.getOrDefault(name, null);
        if (id == null) {
            return null;
        }
        return new Item(id, name);
    }

    //#endregion

}