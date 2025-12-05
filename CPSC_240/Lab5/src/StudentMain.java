import java.util.Random;

public class StudentMain {
    public static void main(String args[]) {
        // make three generic students
        Student alice = new Student("Alice", "Johnson");
        Student bob = new Student("Bob", "Williams");
        Student claire = new Student("Claire", "Smith");

        // starting report
        alice.report();
        bob.report();
        claire.report();

        // we randomly pull credit numbers and grades from these
        // arrays - this gives us reasonable testing data
        int[] credits = {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4};
        String[] grades = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D", "F"};
        Random gen = new Random();

        // we set the seed to a known value to ensure it's always the same data
        gen.setSeed(121);

        // give them each some random classes
        for (int i = 0; i < 42; i++) {
            int creditIdx = gen.nextInt(credits.length);
            int gradeIdx = gen.nextInt(grades.length);
            bob.addCourse(credits[creditIdx], grades[gradeIdx]);

            creditIdx = gen.nextInt(credits.length);
            gradeIdx = gen.nextInt(grades.length);
            alice.addCourse(credits[creditIdx], grades[gradeIdx]);

            creditIdx = gen.nextInt(credits.length);
            gradeIdx = gen.nextInt(grades.length);
            claire.addCourse(credits[creditIdx], grades[gradeIdx]);
        }

        // print reports now
        System.out.println();
        alice.report();
        bob.report();
        claire.report();

        // see if they can graduate
        System.out.printf("\nAlice %s graduate.\n", alice.canGraduate() ? "can" : "CAN'T");
        System.out.printf("Bob %s graduate.\n", bob.canGraduate() ? "can" : "CAN'T");
        System.out.printf("Claire %s graduate.\n", claire.canGraduate() ? "can" : "CAN'T");
    }
}