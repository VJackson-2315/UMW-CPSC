import static org.junit.jupiter.api.Assertions.*;
class StudentTest {

    @org.junit.jupiter.api.Test
    void addCourse() {
        Student s1 = new Student();
        Student s2 = new Student();
        Student s3 = new Student();

        s1.addCourse(5, "A");
        assertEquals(5, s1.getCredits());
        assertEquals(4.0, s1.getGPA(), .1);

        s2.setCredits(15);
        s2.setGPA(3.2);
        s2.addCourse(2, "B+");
        assertEquals(17, s2.getCredits());
        assertEquals(3.2, s2.getGPA(), .1);

        s3.addCourse(10, "F");
        assertEquals(0, s3.getCredits());
        assertEquals(0, s3.getGPA(), .1);
    }

    @org.junit.jupiter.api.Test
    void canGraduate() {
        Student s1 = new Student();
        Student s2 = new Student();
        Student s3 = new Student();
        Student s4 = new Student();

        s1.setCredits(120);
        s1.setGPA(3.7);
        assertEquals(true, s1.canGraduate());

        s2.setCredits(150);
        s2.setGPA(1.3);
        assertEquals(false, s2.canGraduate());

        s3.setCredits(75);
        s3.setGPA(4.0);
        assertEquals(false, s3.canGraduate());

        s4.setCredits(14);
        s4.setGPA(1.8);
        assertEquals(false, s4.canGraduate());
    }

    @org.junit.jupiter.api.Test
    void getYear() {
        Student s1 = new Student();
        Student s2 = new Student();
        Student s3 = new Student();
        Student s4 = new Student();

        s1.setCredits(15);
        assertEquals("First year", s1.getYear());

        s2.setCredits(53);
        assertEquals("Sophomore", s2.getYear());

        s3.setCredits(77);
        assertEquals("Junior", s3.getYear());

        s4.setCredits(130);
        assertEquals("Senior", s4.getYear());
    }
}