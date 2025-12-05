// main program to test the QuizList class
public class Quiz {
    public static void main(String args[]) {
        QuizList quizzes = new QuizList("scores.txt");
        quizzes.dropLowest();
        System.out.println("Average is " + quizzes.average());
    }
}
