import java.util.ArrayList;

public class Student implements Comparable<Student> {
    private String firstName;
    private String lastName;
    private int id;
    private double gpa;
    private int credits;
    private static int nextId = 1000;

    public Student() {
        firstName = "";
        lastName = "";
        id = nextId;
        nextId++;
        gpa = 0.0;
        credits = 0;
    }

    public Student(String fname, String lname) {
        firstName = fname;
        lastName = lname;
        id = getNextId();
        gpa = 0.0;
        credits = 0;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getId() {
        return id;
    }

    private static int getNextId() {
        return nextId++;
    }

    public int getCredits() {
        return credits;
    }

    public double getGPA() {
        return gpa;
    }

    public void setGPA(double gpa) {
        this.gpa = gpa;
    }

    public void setCredits(int credits) {
        this.credits = credits;
    }

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

    public void report() {
        System.out.println(firstName + ", " + lastName + "\t" + id + "\t"
                + String.format("%.2f", gpa) + "\t" + credits);
    }

    public boolean canGraduate() {
        return (credits >= 120) && (gpa >= 2.0);
    }

    public String getYear() {
        if (credits < 30) return "First year";
        else if (credits < 60) return "Sophomore";
        else if (credits < 90) return "Junior";
        else return "Senior";
    }

    @Override
    public int compareTo(Student student) {
        int last = lastName.compareTo(student.getLastName());
        int first = firstName.compareTo(student.getFirstName());
        if (last < 0) {
            return -1;
        } else if (last > 0) {
            return 1;
        } else {
            if (first < 0) {
                return -1;
            } else if (last > 0) {
                return 1;
            } else {
                if (id < student.getId()) {
                    return -1;
                } else if (id > student.getId()) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
}