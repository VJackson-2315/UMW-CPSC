import java.util.ArrayList;
import java.util.Collections;

public class Lab12 {
    public static void main(String args[]) {
        // add some students to an array list
        ArrayList<Student> students = new ArrayList<>();
        students.add(new Student("Ava", "Doherty"));
        students.add(new Student("Amy", "Townsend"));
        students.add(new Student("Sal", "Stevens"));
        students.add(new Student("Kendra", "Bowen"));
        students.add(new Student("Milo", "Dawson"));
        students.add(new Student("Colin", "Key"));
        students.add(new Student("Annie", "Diaz"));
        students.add(new Student("Janiyah", "Ali"));
        students.add(new Student("Boris", "Keller"));
        students.add(new Student("Austin", "Lindsey"));
        students.add(new Student("Dania", "Caldwell"));
        students.add(new Student("Madden", "Oconnor"));
        students.add(new Student("Robert", "Krause"));
        students.add(new Student("Susan", "Elliott"));
        students.add(new Student("Kael", "Ingram"));
        students.add(new Student("Leo", "Martinez"));
        students.add(new Student("Emmy", "Levy"));
        students.add(new Student("Nate", "Flores"));
        students.add(new Student("Duncan", "Elliott"));
        students.add(new Student("Liam", "Landry"));

        // sort the students by name
        Collections.sort(students);

        // and now print them out
        for (Student s : students) {
            s.report();
        }
    }
}