// Student.java
/**
 * @author Tori Jackson
 *This class represents information for a student, including their name, credits, GPA and more
 */
public class Student {
    private String firstName;
    private String lastName;
    private int id;
    private double gpa;
    private int credits;
    private static int nextId = 1000;

    /**
     * A default Student object with no parameters
     * Each student object stores the student's name, ID, GPA and number of credits
     */
    public Student() {
        firstName = "";
        lastName = "";
        id = nextId;
        nextId++;
        gpa = 0.0;
        credits = 0;
    }

    /**
     * Student object that takes the student's name and gets their ID
     * @param fname student's first name
     * @param lname student's last name
     */
    public Student(String fname, String lname) {
        firstName = fname;
        lastName = lname;
        id = getNextId();
        gpa = 0.0;
        credits = 0;
    }

    /**
     * Returns the ID after the current ID
     * @return next ID
     */
    private static int getNextId() {
        return nextId++;
    }

    /**
     * Gets the number of credits
     * @return number of credits
     */
    public int getCredits() {
        return credits;
    }

    /**
     * Returns the student's GPA
     * @return student GPA
     */
    public double getGPA() {
        return gpa;
    }

    /**
     * Changes the student's GPA
     * @param gpa number to change the GPA to
     */
    public void setGPA(double gpa) {
        this.gpa = gpa;
    }

    /**
     * Changes the student's number of credits
     * @param credits number to change the number of credits to
     */
    public void setCredits(int credits) {
        this.credits = credits;
    }

    /**
     * Checks the student's grade in a course before adding the course's credits to the
     * student's overall number of credits
     * @param creds Number of credits the course offers
     * @param grade Student's current grade in the course
     * @throws IllegalArgumentException If the grade given is not a valid grade
     */
    public void addCourse(int creds, String grade) throws IllegalArgumentException {
        double gradeGPA;
        if (grade.equals("A")) gradeGPA = 4.0;
        else if (grade.equals("A-")) gradeGPA = 3.7;
        else if (grade.equals("B+")) gradeGPA = 3.3;
        else if (grade.equals("B")) gradeGPA = 3.0;
        else if (grade.equals("B-")) gradeGPA = 2.7;
        else if (grade.equals("C+")) gradeGPA = 2.3;
        else if (grade.equals("C")) gradeGPA = 2.0;
        else if (grade.equals("C-")) gradeGPA = 1.7;
        else if (grade.equals("D+")) gradeGPA = 1.3;
        else if (grade.equals("D")) gradeGPA = 1.0;
        else if (grade.equals("F")) gradeGPA = 0.0;
        else throw new IllegalArgumentException();

        gpa = ((gpa * credits) + (gradeGPA * creds)) / (credits + creds);

        if (gradeGPA > 0) {
            credits += creds;
        }
    }

    /**
     * Prints out a report with the student's name, ID, GPA and number of credits
     */
    public void report() {
        System.out.println(firstName + ", " + lastName + "\t" + id + "\t"
                + String.format("%.2f", gpa) + "\t" + credits);
    }

    /**
     * Determines whether a student can graduate depending on their GPA and the number of credits
     * @return true if credits is 120 or higher, and their GPA is above a 2.0, otherwise returns false
     */
    public boolean canGraduate() {
        return (credits >= 120) && (gpa >= 2.0);
    }

    /**
     * Returns the student's year depending on the credits they have
     * @return student's year
     */
    public String getYear() {
        if (credits < 30) return "First year";
        else if (credits < 60) return "Sophomore";
        else if (credits < 90) return "Junior";
        else return "Senior";
    }
}
