import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

/**
 * Picks the answer, as well as the user's guess
 */
public class GetInput {

    /**
     * checks the validity of the user's input
     * @param input
     * @return if the input is valid or not
     * @throws FileNotFoundException
     */
    public static boolean valid(String input) throws FileNotFoundException {
        ArrayList<String> wordList = WordFile.getFile("words.txt");
        if (input.length() != 5) {
            return false;
        } else {
            if (wordList.contains(input)) {
                return true;
            } else {
                return false;
            }
        }
    }

    /**
     * Returns a random word as the answer
     * @return random word
     * @throws FileNotFoundException
     */
    public static String getAnswer() throws FileNotFoundException {
        Random rand = new Random();

        ArrayList<String> words = WordFile.getFile("words.txt");
        String answer = words.get(rand.nextInt(4499));

        //For testing purposes, we will use index 15

        return answer;
    }

    /**
     * Asks the user for their guess, then stores it.
     * If the word is invalid, it prints one of three reasons why it may be invalid
     * @return the user's guess
     * @throws FileNotFoundException
     */
    public static String getWord() throws FileNotFoundException {
        Scanner in = new Scanner(System.in);

        System.out.printf("%nWhat is your guess? ");
        String input = in.nextLine();

        while (!valid(input)) {
            if (input.length() > 5) {
                System.out.printf("Your word is too long. Try again.%n%n");
            } else if (input.length() < 5) {
                System.out.printf("Your word is too short. Try again.%n%n");
            } else {
                System.out.printf("Your word is not valid. Try again.%n%n");
            }
            System.out.print("What is your guess? ");
            input = in.nextLine();
        }
        return input;
    }
}
