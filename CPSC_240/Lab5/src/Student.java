public class Student {
    private String firstName;
    private String lastName;
    private int id;
    private double gpa;
    private int credits;

    private static int nextId = 1000;

    public int getNextId() {
        int next = nextId;
        nextId += 1;
        return next;
    }

    public Student(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;

        id = getNextId();
        gpa = 0.00;
        credits = 0;
    }

    public double getScore (String grade) {
        if (grade.equalsIgnoreCase("A")) {
            return 4.00;
        } else if (grade.equalsIgnoreCase("A-")) {
            return 3.70;
        } else if (grade.equalsIgnoreCase("B+")) {
            return 3.30;
        } else if (grade.equalsIgnoreCase("B")) {
            return 3.00;
        } else if (grade.equalsIgnoreCase("B-")) {
            return 2.70;
        } else if (grade.equalsIgnoreCase("C+")) {
            return 2.30;
        } else if (grade.equalsIgnoreCase("C")) {
            return 2.00;
        } else if (grade.equalsIgnoreCase("C-")) {
            return 1.70;
        } else if (grade.equalsIgnoreCase("D+")) {
            return 1.30;
        } else if (grade.equalsIgnoreCase("D")) {
            return 1.00;
        } else if (grade.equalsIgnoreCase("F")) {
            return 0;
        } else {
            throw new IllegalArgumentException("Invalid grade");
        }
    }

    public void addCourse(int credits, String grade) {
        double gradeScore = getScore(grade);
        this.gpa = (((this.gpa * this.credits) + gradeScore * credits) / (this.credits + credits));

        if (!grade.equalsIgnoreCase("F")) {
            this.credits += credits;
        }
    }

    public void report() {
        System.out.printf("%s, %s | %d | %.2f | %d%n",
                this.lastName, this.firstName, this.id, this.gpa, this.credits);
    }

    public boolean canGraduate() {
        if (this.credits >= 120 && this.gpa >= 2.0) {
            return true;
        } else {
            return false;
        }
    }
}
