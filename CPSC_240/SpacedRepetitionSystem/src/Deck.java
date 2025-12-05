import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

import static java.lang.Math.round;

/**
 * Creates a deck of study cards
 */
public class Deck {
    private String filename;
    private ArrayList<Card> cards;

    /**
     * Creates an empty deck from user input
     */
    public Deck() {
        Scanner in = new Scanner(System.in);

        filename = "decks/" + in.nextLine().toLowerCase() + ".deck.txt";
        cards = new ArrayList<>();
    }

    /**
     * Creates a deck from a txt file
     * @param filename
     */
    public Deck(String filename) {
        this.filename = filename;
        this.cards = new ArrayList<>();
        Scanner in = null;

        try {
            FileInputStream file = new FileInputStream(filename);
            in = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.out.println("Error: file could not be found!");
            System.exit(-1);
        }
        while(in.hasNextLine()) {
            Card card = new Card(in);
            cards.add(card);
            in.nextLine();
        }
    }

    /**
     *
     * @return name of file
     */
    public String getFilename() {
        return filename;
    }

    /**
     * Saves all cards in deck into the txt file
     */
    public void save() {
        PrintWriter out = null;
        try {
            out = new PrintWriter(new FileOutputStream(filename));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }

        for (int i = 0; i < cards.size(); i++) {
            Card c = cards.get(i);
            c.save(out);
            out.println();
        }
        out.close();
    }

    /**
     * Adds a new card to the deck
     * @param card
     */
    public void addCard(Card card) {
        cards.add(card);
        save();
    }

    /**
     * Shuffles the deck (10 new cards plus due cards)
     * @param studyDeck
     */
    public void shuffle(ArrayList<Card> studyDeck) {
        //Shuffle the cards
        ArrayList<Card> newCards = new ArrayList<>();
        ArrayList<Card> dueCards = new ArrayList<>();
        ArrayList<Card> discard = new ArrayList<>();
        while(!studyDeck.isEmpty()) {
            Random rand = new Random();
            Card card = studyDeck.get(rand.nextInt(studyDeck.size()));
            if (!card.ask()) {
                discard.add(card);
            } else {
                if (card.isNew()) {
                    newCards.add(card);
                } else if (card.isDue() && !card.isNew()) {
                    dueCards.add(card);
                }
            }
            studyDeck.remove(card);
        }

        if (!newCards.isEmpty()) {
            int i = 0;
            while (i < 10) {
                if (newCards.size() < 10) {
                    i = 11;
                    studyDeck.addAll(newCards);
                } else {
                    studyDeck.add(newCards.get(i));
                    i++;
                }
            }
        }

        studyDeck.addAll(dueCards);
        if (studyDeck.isEmpty()) {
            System.out.println("There is nothing here to study.");
            System.out.println("Returning to Menu");
            return;
        }
    }

    /**
     * Has the user study certain cards until there are none
     */
    public void study() {
        ArrayList<Card> studyDeck = new ArrayList<>(cards);
        clearScreen();
        if (!studyDeck.isEmpty()) {
            while (!studyDeck.isEmpty()) {
                shuffle(studyDeck);
                for (int i = 0; i < studyDeck.size(); i++) {
                    Scanner in = new Scanner(System.in);
                    Card card = studyDeck.get(i);
                    int numDays = card.getDaysBetween();

                    System.out.println(card.getQuestion());
                    pause();
                    System.out.println("Press 'enter' to get the answer");
                    in.nextLine();
                    System.out.println(card.getAnswer());
                    pause();
                    System.out.println("Was the question easy(1), correct(2), difficult(3) or wrong(4)?");

                    int input = in.nextInt();
                    switch (input) {
                        case 1: //easy
                            numDays = (int) round((numDays + 1) * 1.5);
                            break;
                        case 2: //correct
                            numDays = (int) round((numDays + 1) * 1.25);
                            break;
                        case 3: //difficult
                            numDays = (int) round((numDays + 1) * 1.1);
                            break;
                        case 4: //wrong
                            numDays = 0;
                            break;
                    }
                    card.update(numDays);
                    pause();
                    clearScreen();
                }
                save();

                int i = 0;
                while (i < studyDeck.size()) {
                    Card card = studyDeck.get(i);
                    if (!card.ask()) {
                        studyDeck.remove(i);
                    } else {
                        i++;
                    }
                }
            }
            System.out.println("You finished the session");
        } else {
            System.out.println("No cards in deck");
        }
        System.out.println("Returning to Menu");
    }

    /**
     * Pauses the program
     */
    public void pause() {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("Got interrupted!");
        }
    }

    /**
     * Clears the screen
     */
    public void clearScreen() {
        for (int i = 0; i < 100; i++) {
            System.out.println();
        }
    }
}
