import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Runs the program
 */
public class Main {
    /**
     * Pauses the program
     */
    public static void pause() {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("Got interrupted!");
        }
    }

    /**
     * Clears the screen
     */
    public static void clearScreen() {
        for (int i = 0; i < 100; i++) {
            System.out.println();
        }
    }

    /**
     * Checks if a folder to hold the decks exists
     * @return a new folder if there is none
     */
    public static File checkFolder() {
        File folder = new File("decks");
        if (!folder.exists()) {
            folder.mkdirs();
        }
        return folder;
    }

    /**
     * Gets the list of existing decks in the folder
     * @return a list of the filenames
     */
    public static ArrayList<String> getDecks() {
        File folder = checkFolder();
        File[] list =folder.listFiles();
        ArrayList<String> decks = new ArrayList<>();
        for (int i = 0; i < list.length; i++) {
            String deckName = list[i].getName();
            int dot = deckName.indexOf(".");
            deckName = deckName.substring(0, dot);
            decks.add(deckName);
        }
        return decks;
    }

    /**
     * Has the user choose their deck of choice
     * @return user deck of choice
     */
    public static Deck chooseDeck() {
        ArrayList<String> decks = getDecks();
        Scanner in = new Scanner(System.in);
        System.out.println("Choose your deck:");
        for (int i = 0; i <decks.size(); i++) {
            System.out.printf("%d. %s %n", i+1, decks.get(i));
        }

        int input = in.nextInt();
        int range = decks.size() + 1;

        while (input >= range) {
            System.out.println("Invalid input. Try again");
            input = in.nextInt();
        }
        return new Deck("decks/" + decks.get(input-1) + ".deck.txt");
    }

    /**
     * Studies from a deck
     */
    public static void study() {
        Deck deck = chooseDeck();
        deck.study();
    }

    /**
     * Adds cards to a deck infinitely until the user exits
     */
    public static void addCards() {
        Scanner in = new Scanner(System.in);
        Deck deck = chooseDeck();

        System.out.println("Enter a question. (Type 'EXIT' to exit)");
        String question = in.nextLine();
        while(!question.equals("EXIT")) {

            System.out.println("Enter an answer. (Type 'EXIT' to exit)");
            String answer = in.nextLine();
            if(answer.equals("EXIT")) {
                break;
            }

            Card card = new Card(question, answer);
            deck.addCard(card);

            pause();
            System.out.println();

            System.out.println("Enter a question. (Type 'EXIT' to exit)");
            question = in.nextLine();
        }
    }

    /**
     * Creates a new deck and adds it to the decks folder
     */
    public static void createDeck() {
        System.out.println("Name your deck");
        Deck newDeck = new Deck();

        try {
            File deckFile = new File(newDeck.getFilename());
            if (!deckFile.createNewFile()) {
                System.out.println("This deck already exists.");
                return;
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        File folder = checkFolder();
        Scanner in = new Scanner(System.in);
        String menu = "1. Study a Deck %n2. Create a New Deck %n3. Add New Cards to a Deck%n4+. Exit%n";

        System.out.println("------------------");
        System.out.printf(menu);

        int input = in.nextInt();

        while (input <= 3) {
            ArrayList<String> checkDecks = getDecks();

            System.out.println();
            switch (input) {
                case 1:
                    if(!checkDecks.isEmpty()) {
                        study();
                    } else {
                        System.out.println("No decks to study");
                        System.out.println("Returning to Menu");
                    }
                    break;
                case 2:
                    createDeck();
                    break;
                case 3:
                    if(!checkDecks.isEmpty()) {
                        addCards();
                    } else {
                        System.out.println("No decks to modify");
                        System.out.println("Returning to Menu");
                    }
                    break;
            }

            pause();
            pause();
            clearScreen();

            System.out.println("------------------");
            System.out.printf(menu);

            input = in.nextInt();
        }
    }
}
