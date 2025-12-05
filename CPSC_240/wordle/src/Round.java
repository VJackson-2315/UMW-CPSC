import java.util.ArrayList;
import java.util.Collections;

/**
 * Runs a round of Wordle
 */
public class Round {
    /**
     * Converts a word into an arrayList of it's letters
     * @param word
     * @return an arrayList of the word's letters
     */
    public static ArrayList<String> convert(String word) {
        ArrayList<String> arr = new ArrayList<>();;
        for (int i = 0; i < word.length(); i++) {
            String letter = String.valueOf(word.charAt(i));
            arr.add(letter);
        }

        return arr;
    }

    /**
     * Checks if the user's full guess is correct or not
     * @param word
     * @param input
     * @return of the user was correct
     */
    public static boolean checkStatus(String word, String input) {
        if (input.equalsIgnoreCase(word)) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Tells the user if their guess was correct or not
     * If it is not correct, the method lists any correct letters and misplaced letters.
     * If none of the letters are correct, the method tells that to the user.
     * @param word
     * @param input
     */
    public static void roundScore(String word, String input) {
        int wrongGuess = 0;

        if (checkStatus(word, input)) { //If the input is equal to the answer
            System.out.println("Congratulations, you got it!");
        } else { //If the answer is not correct
            ArrayList<String> wordChar = convert(word);
            ArrayList<String> inputChar = convert(input);

            for (int i = 0; i < inputChar.size(); i++) {
                String letter = inputChar.get(i);
                String character = wordChar.get(i);

                if (letter.equalsIgnoreCase(character)) {
                    System.out.printf("The %s is right!%n", letter);
                    wordChar.set(i, "_");
                    inputChar.set(i, "_");
                    wrongGuess -= 1;
                }
            }

            for (int i = 0; i < inputChar.size(); i++) {
                String letter = inputChar.get(i);
                String character = wordChar.get(i);

                if (wordChar.contains(letter) && !letter.equalsIgnoreCase("_")) {
                    System.out.printf("There is a %s but not here.%n", letter);
                    Collections.replaceAll(wordChar, letter, "_");
                } else {
                    wrongGuess += 1;
                }
            }

            if (wrongGuess == 5) {
                System.out.println("There were no correct letters in your guess.");
            }
            wrongGuess -= wrongGuess;
        }
    }
}

