package eu.epitech.trantor;

/**
 * Team
 */
public class Team {

    //#region Properties

    private Integer id;
    private String name;

    //#endregion

    //#region Constructor

    public Team(Integer id, String name) {
        this.id = id;
        this.name = name;
    }

    //#endregion

    //#region Methods

    /**
     * @return the id
     */
    public Integer getId() {
        return id;
    }

    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    //#endregion

}