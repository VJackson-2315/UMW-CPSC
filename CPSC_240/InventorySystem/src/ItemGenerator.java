import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

/**
 * Creates and generates random items
 */
public class ItemGenerator {
    // Weapons
    private static Item uchigatana = new Item("Uchigatana", ItemType.Weapon, 5.5, 100, 115);
    private static Item longbow = new Item("Longbow", ItemType.Weapon, 4.0, 100, 82);
    private static Item claymore = new Item("Claymore", ItemType.Weapon, 9.0, 50, 138);
    private static Item broken = new Item("Broken Straight Sword", ItemType.Weapon, 1.0, 3, 70);
    private static Item moonlight = new Item("Moonlight Greatsword", ItemType.Weapon, 10.5, 2000, 199);

    // Armor
    private static Item knight = new Item("Knight Helm", ItemType.Armor, 5.1, 150, 5);
    private static Item firelink = new Item("Firelink Armor", ItemType.Armor, 8.6, 2000, 12);
    private static Item execute = new Item("Executioner's Gauntlets", ItemType.Armor, 5.3, 200, 5);
    private static Item herald = new Item ("Herald Leggings", ItemType.Armor, 5.3, 100, 7);
    private static Item dancer = new Item("Dancer's Crown", ItemType.Armor, 2.8, 1000, 3);

    // Consumables
    private static Item estus = new Item("Estus Flask", ItemType.Consumable, 1.0, 0, 250);
    private static Item bone = new Item("Homeward Bone", ItemType.Consumable, 0.5, 100, 0);
    private static Item gold = new Item("Gold Pine Resin", ItemType.Consumable, 0.1, 100, 95);
    private static Item frost = new Item("Rime-Blue Moss Clump", ItemType.Consumable, 0.1, 50, 45);
    private static Item siegbrau = new Item("Siegbräu", ItemType.Consumable, 1.5, 1000, 100);

    // Misc.
    private static Item rubbish = new Item();
    private static Item firebomb = new Item("Firebomb", ItemType.Miscellaneous, 1.5, 10, 100);


    private static ArrayList<Item> items = new ArrayList<>
            (Arrays.asList(uchigatana, longbow, claymore, broken, moonlight,
                    knight, firelink, herald, execute, dancer,
                    estus, bone, gold, frost, siegbrau,
                    rubbish, firebomb));

    /**
     * Generates a random item
     * @return random item
     */
    public static Item generate() {
        Random rand = new Random();
        Item item = items.get(rand.nextInt(items.size()));
        items.remove(item);

        return item;
    }

    /**
     * Returns an item back to the random generated list
     * @param item
     */
    public static void returnItem(Item item) {
        items.add(item);
    }
}
