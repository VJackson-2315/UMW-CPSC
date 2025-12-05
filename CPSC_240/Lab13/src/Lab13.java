import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class Lab13 {
    public static HashMap<String, Integer> getTable(String filename) {
        HashMap<String, Integer> table = new HashMap<>();
        Scanner in;
        try {
            FileInputStream file = new FileInputStream(filename);
            in = new Scanner(file);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        while (in.hasNext()) {
            String word = in.next();
            int value = 1;

            if (table.containsKey(word)) {
                value += table.get(word);
                table.replace(word, value);
            } else {
                table.put(word, value);
            }
        }

        return table;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Please enter the file name");
        HashMap<String, Integer> words = getTable(in.nextLine());
        System.out.println("Please enter the number of words to view");
        int count = in.nextInt();

        for (int i = 1; i <= count; i++) {
            String maxWord = "";
            Integer maxCount = 0;
            for (String word: words.keySet()) {
                int wordCount = words.get(word);
                if (wordCount > maxCount) {
                    maxWord = word;
                    maxCount = words.get(word);
                }
            }
            System.out.printf("#%d: %s (%d uses)%n", i, maxWord, maxCount);
            words.remove(maxWord);
        }
    }
}
