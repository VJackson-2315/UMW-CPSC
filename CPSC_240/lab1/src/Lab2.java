import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;

public class Lab2 {
    public static ArrayList<String> getInput() {
        ArrayList<String> names = new ArrayList<>();
        System.out.println("Give a list of names in 'Lastname, Firstname' format. (Return nothing when done)");
        Scanner in = new Scanner(System.in);

        while (true) {
            String next = in.nextLine();
            if (next.isEmpty()){
                break;
            } else {
                names.add(next);
            }
        }
        Collections.sort(names, String.CASE_INSENSITIVE_ORDER);

        for (int i = 0; i < names.size(); i++) {
            String next = names.get(i);
            String last = next.substring(0, next.indexOf(","));
            String first = next.substring(next.indexOf(",") + 2);
            next = first + " " + last;
            names.set(i, next);
        }

        return names;
    }

    public static void main(String[] args) {
        ArrayList<String> names = getInput();

        for (int i = 0; i < names.size(); i++) {
            System.out.printf("%d. %s %n", i+1, names.get(i));
        }
    }
}
