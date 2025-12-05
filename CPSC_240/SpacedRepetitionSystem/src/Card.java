import java.io.PrintWriter;
import java.time.LocalDate;
import java.util.Scanner;

/**
 * Generates a card from user information or text file information
 */
public class Card {
    private String question;
    private String answer;
    private int daysBetween;
    private LocalDate dueDate;
    private boolean newCard;

    /**
     * Creates a card from user input
     * @param question
     * @param answer
     */
    public Card(String question, String answer) {
        this.question = question;
        this.answer = answer;
        daysBetween = 0;
        dueDate = LocalDate.now();
        newCard = true;
    }

    /**
     * Creates a card from a text file
     * @param in
     */
    public Card(Scanner in) {
        question = in.nextLine();
        answer = in.nextLine();
        daysBetween = Integer.parseInt(in.nextLine());
        dueDate = LocalDate.parse(in.nextLine());
        newCard = Boolean.parseBoolean(in.nextLine());
    }

    /**
     *
     * @return card question
     */
    public String getQuestion() {
        return question;
    }

    /**
     *
     * @return card answer
     */
    public String getAnswer() {
        return answer;
    }

    /**
     *
     * @return number of days between study sessions
     */
    public int getDaysBetween() {
        return daysBetween;
    }

    /**
     * Updates the card's information after studying
     * @param numDays new number of daysBetween
     */
    public void update(int numDays) {
        this.daysBetween = numDays;

        if (daysBetween != 0) {
            this.dueDate = dueDate.plusDays(daysBetween);
        }
        else {
            this.dueDate = LocalDate.now();
        }

        this.newCard = false;
    }

    /**
     * Saves cards into a file
     * @param out
     */
    public void save(PrintWriter out) {
        out.println(question);
        out.println(answer);
        out.println(daysBetween);
        out.println(dueDate);
        out.println(newCard);
    }

    /**
     *
     * @return if the card's dueDate is now
     */
    public boolean isDue() {
        if (this.dueDate.equals(LocalDate.now())) {
            return true;
        }
        else {
            return false;
        }
    }

    /**
     *
     * @return if the card is new or not
     */
    public boolean isNew() {
        if(this.newCard) {
            return true;
        }
        else {
            return false;
        }
    }

    /**
     *
     * @return if the card should be studied or not (new or due)
     */
    public boolean ask() {
        if (isDue() || isNew()) {
            return true;
        }
        else {
            return false;
        }
    }
}
