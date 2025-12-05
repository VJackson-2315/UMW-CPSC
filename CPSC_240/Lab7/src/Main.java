import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Family> families = new ArrayList<>();
        int boysTotal = 0;
        int girlsTotal = 0;

        double boysPerc = 0;
        double girlsPerc = 0;

        int total = 0;

        for (int index = 1; index <= 1000000; index++) {
            families.add(new Family());
        }

        for (Family fam : families) {
            fam.haveChildren();
            boysTotal += fam.getNumBoys();
            girlsTotal += fam.getNumGirls();
        }

        total += boysTotal + girlsTotal;

        boysPerc = ((double)boysTotal / total) * 100;
        girlsPerc = ((double)girlsTotal / total) * 100;

        System.out.println(total);

        System.out.printf("The total number of boys was %d%n", boysTotal);
        System.out.printf("The total number of girls was %d%n", girlsTotal);

        System.out.printf("%nThe total percentage of boys was %.2f%% %n", boysPerc);
        System.out.printf("The total percentage of girls was %.2f%% %n", girlsPerc);
    }
}

// The ratio is almost a split 50/50, with some cases being 49.99/50.01 and vice versa.