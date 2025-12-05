import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Sum {
    public static void main(String args[]) {
        // open the file
        FileReader reader = null;
        try {
            reader = new FileReader("data.txt");
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
            System.exit(0);
        }

        // make a scanner from it
        Scanner in = new Scanner(reader);

        // read all the numbers
        int sum = 0;
        while (in.hasNext()) {
            try {
                sum += in.nextInt();
            } catch (InputMismatchException e) {
                in.next();
            }
        }

        // print the sum
        System.out.println("Sum is " + sum + ".");
    }
}
