/**
 * Creates an item object
 */
public class Item {
    private String name;
    private ItemType type;
    private double weight;
    private int value;
    private int strength;

    /**
     * Generates a default item (rubbish)
     */
    public Item() { // Default Constructor
        name = "Rubbish";
        type = ItemType.Miscellaneous;
        weight = 0.1;
        value = 1;
        strength = 0;
    }

    /**
     * Generates an item with said parameters
     * @param name
     * @param type
     * @param weight
     * @param value
     * @param strength
     */
    public Item(String name, ItemType type, double weight, int value, int strength) {
        this.name = name;
        this.type = type;
        this.weight = weight;
        this.value = value;
        this.strength = strength;
    }

    /**
     * Returns item name
     * @return
     */
    public String getName() {
        return this.name;
    }

    /**
     * returns item type
     * @return
     */
    public ItemType getType() {
        return this.type;
    }

    /**
     * returns item weight
     * @return
     */
    public double getWeight() {
        return this.weight;
    }

    /**
     * returns item value
     * @return
     */
    public int getValue() {
        return this.value;
    }

    /**
     * returns item strength
     * @return
     */
    public int getStrength() {
        return this.strength;
    }

}