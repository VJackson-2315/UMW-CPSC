import java.util.ArrayList;
import java.util.Scanner;

public class Inventory {
    private static ArrayList<Item> inventory;
    private static double weightLimit;
    private static Item equippedWeapon;
    private static Item equippedArmor;

    /**
     * Generates the inventory
     */
    public Inventory() {
        weightLimit = 55.00;
        inventory = new ArrayList<Item>();
        equippedWeapon = null;
        equippedArmor = null;
    }

    /**
     *
     * @return Inventory
     */
    public ArrayList<Item> getInventory() {
        return inventory;
    }

    /**
     * Adds a random item if it fits into the current weight limit
     * @param item
     */
    public static void add(Item item) {
        if (totalWeight(item)) {
            if (!inventory.contains(item)) {
                weightLimit -= item.getWeight();
                inventory.add(item);
                System.out.printf("The %s was added to your inventory.%n%n", item.getName());
            }
        }
    }

    /**
     * Checks if an item can fit into the inventory based on weight
     * @param item
     * @return if the item can fit
     */
    public static boolean totalWeight(Item item) {
        if (item.getWeight() <= weightLimit) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Prints out a list of items
     * @param array ArrayList that will be printed out
     * @param opt Determines if the print needs numberings or not
     */
    public static void print(ArrayList<Item> array, int opt) {
        if (array.isEmpty()) { //Checks if the inventory/list is empty
            System.out.println("There's nothing here to do");
        } else {
            String header = "Item                       Weight         Value   Strength";
            if (opt != 1){
                header = "   Item                       Weight         Value   Strength";
            }
            System.out.println(header);

            for (int i = 0; i < array.size(); i++) {
                Item item = array.get(i);
                String name = item.getName();
                double weight = item.getWeight();
                int value = item.getValue();
                int strength = item.getStrength();

                String status = "";
                String w = "" + weight;
                String v = "" + value;
                String s = "" + strength;

                String spaces1 = "";
                String spaces2 = "";
                String spaces3 = "";

                int numSpaces1 = 33 - (name.length() + w.length());;
                int numSpaces2 = 14 - v.length();
                int numSpaces3 = 11 - s.length();

                String str = "";

                if (opt != 1) {
                    numSpaces1 = 33 - (name.length() + w.length());;
                    numSpaces2 = 14 - v.length();
                    numSpaces3 = 11 - s.length();

                    name = (i + 1) + ". " + name;

                    if (i + 1 >= 10) {
                        numSpaces1 -= 1;
                    }
                }

                for (int index = 0; index < numSpaces1; index++){
                    spaces1 += " ";
                }

                for (int index = 0; index < numSpaces2; index++){
                    spaces2 += " ";
                }
                for (int index = 0; index < numSpaces3; index++){
                    spaces3 += " ";
                }

                if (item == equippedWeapon) {
                    status = "(equipped weapon)";
                } else if (item == equippedArmor) {
                    status = "(equipped armor)";
                }

                str += "%s%s%.1f%s%d%s%d %s%n";

                System.out.printf(str, name, spaces1, weight, spaces2, value, spaces3, strength, status);
            }
            if (opt == 1) {
                System.out.println();
            }
        }
    }

    /**
     * Removes an item from the inventory and returns it back to the generator
     */
    public static void drop() {
        Scanner in = new Scanner(System.in);
        System.out.println("Drop an Item");
        print(inventory, 2);

        if (inventory.size() == 0){
            return;
        }

        System.out.printf("%d. Cancel%n", inventory.size()+1);

        int input = in.nextInt();
        int range = inventory.size() + 1;

        while (input > range) {
            System.out.println("Invalid input. Try again");
            input = in.nextInt();
        }
        if (input == range) {
            return;
        } else {
            input -= 1;
            Item dropped = inventory.get(input);
            System.out.printf("You dropped the %s %n", dropped.getName());
            inventory.remove(input);

            ItemGenerator.returnItem(dropped);
            weightLimit += dropped.getWeight();
        }
    }

    /**
     * Creates a list of the weapons in the inventory for the user to equip
     */
    public static void equipWeapon() {
        Scanner in = new Scanner(System.in);
        ArrayList<Item> weapons = new ArrayList<Item>(inventory);

        for (int index = 0; index < inventory.size(); index++) {
            Item weapon = inventory.get(index);
            if (weapon.getType() != ItemType.Weapon) {
                weapons.remove(weapon);
            }
        }
        System.out.println("Equip a Weapon");
        print(weapons, 2);

        if (weapons.isEmpty()){
            return;
        }

        System.out.printf("%d. Cancel%n", weapons.size()+1);

        int input = in.nextInt();
        int range = weapons.size() + 1;

        while (input > range) {
            System.out.println("Invalid input. Try again");
            input = in.nextInt();
        }
        if (input == range) {
            return;
        } else {
            input -= 1;
            equippedWeapon = weapons.get(input);
            System.out.printf("You equipped the %s. %n%n", equippedWeapon.getName());
        }
    }

    /**
     * Creates a list of the armor in the inventory for the user to equip
     */
    public static void equipArmor() {
        Scanner in = new Scanner(System.in);
        ArrayList<Item> arms = new ArrayList<Item>(inventory);

        for (int index = 0; index < inventory.size(); index++) {
            Item armor = inventory.get(index);
            if (armor.getType() != ItemType.Armor) {
                arms.remove(armor);
            }
        }
        System.out.println("Equip a Weapon");
        print(arms, 2);

        if (arms.size() == 0){
            return;
        }

        System.out.printf("%d. Cancel%n", arms.size()+1);

        int input = in.nextInt();
        int range = arms.size() + 1;

        while (input > range) {
            System.out.println("Invalid input. Try again");
            input = in.nextInt();
        }
        if (input == range) {
            return;
        } else {
            input -= 1;
            equippedArmor = arms.get(input);
            System.out.printf("You equipped the %s. %n%n", equippedArmor.getName());
        }
    }
}