import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

class QuizList {
    private ArrayList<Integer> numbers = new ArrayList<>();

    public QuizList(String fileName) {
        // open the file
        Scanner input = null;
        try {
            FileInputStream file = new FileInputStream(fileName);
            input = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.out.println("Error, file could not be found!");
            System.exit(-1);
        }

        // read the data
        while (input.hasNext()) {
            numbers.add(input.nextInt());
        }
    }

    // drop the lowest grade out of the list
    public void dropLowest() {
        // sort the data in ascending order
        Collections.sort(numbers);
        // then drop the first element out
        numbers.remove(0);
    }

    // return the average of the numbers back
    public double average() {
        int sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            sum += numbers.get(i);
        }

        return (double) sum / (double) numbers.size();
    }
}
