import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;

/**
 * checks for the correct file, then creates an ArrayList
 */
public class WordFile {

    /**
     * checks for the correct file, then returns it as an ArrayList
     * @param file
     * @return array list of the potential words
     * @throws FileNotFoundException
     */
    public static ArrayList<String> getFile(String file) throws FileNotFoundException {
        // Function should grab the words.txt file and print out the list
        ArrayList<String> wordList = new ArrayList<String>();
        String word;

        if (file.equalsIgnoreCase("words.txt")){
            new Scanner(new File("words.txt"));
            Scanner fIn = new Scanner(new FileInputStream(file));

            int index = 0;
            while(fIn.hasNext()) {
                String line = fIn.nextLine();
                wordList.add(line);
                index++;
            }

            fIn.close();
            return wordList;

        } else {
            System.err.println("Invalid file. Try 'words.txt' instead");
            return null;
        }
    }
}
