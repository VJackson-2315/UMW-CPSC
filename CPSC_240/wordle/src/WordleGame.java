import java.io.FileNotFoundException;

/**
 * Plays a full game of Wordle
 */
public class WordleGame {
    public static void main(String[] args) throws FileNotFoundException {
        System.out.printf("You have six tries to guess a five-letter word.%n");
        int roundCount = 1;
        System.out.printf("%nRound %d", roundCount);

        String word = GetInput.getAnswer();
        // System.out.printf("%nFor testing, the answer is %s. %n", word);
        String input = GetInput.getWord();

        while (roundCount < 6){
            Round.roundScore(word, input);
            if (Round.checkStatus(word, input)) {
                roundCount = 6;
            } else {
                roundCount += 1;
                System.out.printf("%nRound %d", roundCount);
                input = GetInput.getWord();
            }
        }

        if (roundCount == 6 && !Round.checkStatus(word, input)) {
            System.out.printf("Sorry, the word is %s", word);
        }
    }
}
