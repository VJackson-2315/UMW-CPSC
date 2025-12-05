import java.util.Scanner;

public class Lab1 {
    public static void song(int bottles, String beverage) {
        int amount = bottles;
        String lyric1 = "%d bottles of %s on the wall, %d bottles of %s.%n";
        String lyric2 = "Take one down and pass it around, %d bottles of %s on the wall.%n%n";

        while (bottles > 1) {
            System.out.printf(lyric1, bottles, beverage, bottles, beverage);
            bottles -= 1;

            if (bottles > 2) {
                System.out.printf(lyric2, bottles, beverage);
            } else {
                System.out.printf("Take one down and pass it around, %d bottle of %s on the wall.%n%n",
                         bottles, beverage);
            }
        }

        if (bottles == 1){
            System.out.printf("%d bottle of %s on the wall, %d bottle of %s.%n",
                    bottles, beverage, bottles, beverage);

            bottles -= 1;

            System.out.printf(lyric2, bottles, beverage);
        }

        if (bottles == 0){
            System.out.printf(lyric1, bottles, beverage, bottles, beverage);
            System.out.printf("Go to the store and buy some more, %d bottles of %s on the wall.%n%n",
                    amount, beverage);
        }
    }

    public static void main(String[] arg){
        System.out.printf("What drink are you having?%n");
        Scanner in = new Scanner(System.in);
        String drink = in.nextLine();

        System.out.printf("How many bottles of %s do you have?%n", drink);
        in = new Scanner(System.in);
        int amount = in.nextInt();

        song(amount, drink);
    }
}
