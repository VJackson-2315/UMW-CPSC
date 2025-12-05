import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Inventory inventory = new Inventory();
        Scanner in = new Scanner(System.in);
        String menu = "1. Print inventory %n2. Add random item %n3. Drop item %n4. Equip Weapon %n5. Equip Armor %n6. Exit %n";

        System.out.println("------------------");
        System.out.printf(menu);

        int input = in.nextInt();
        while (input > 6) {
            System.out.printf("Invalid input. Try again%n%n");

            System.out.println("------------------");
            System.out.printf(menu);

            input = in.nextInt();
        }

        while (input <= 5) {
            switch (input) {
                case 1:
                    inventory.print(inventory.getInventory(), 1);
                    break;
                case 2:
                    inventory.add(ItemGenerator.generate());
                    break;
                case 3:
                    inventory.drop();
                    break;
                case 4:
                    inventory.equipWeapon();
                    break;
                case 5:
                    inventory.equipArmor();
                    break;
            }

            System.out.println("------------------");
            System.out.printf(menu);

            input = in.nextInt();
        }
    }
}