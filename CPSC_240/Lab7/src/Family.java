import java.util.Random;

public class Family {
    // Guess: The ratio is 25/75

    private static Random rand = new Random();
    private int numGirls;
    private int numBoys;

    public void haveChildren() {
        int child = rand.nextInt(0, 2);
        while (child == 0) {
            numBoys++;
            child = rand.nextInt(0, 2);
        }
        if (child == 1) {
            numGirls++;
        }
    }

    public int getNumGirls() {
        return numGirls;
    }

    public int getNumBoys() {
        return numBoys;
    }
}
