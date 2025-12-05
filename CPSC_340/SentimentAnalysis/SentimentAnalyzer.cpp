//
// Created by Victoria Jackson on 11/15/2025.
//

#include "SentimentAnalyzer.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>

using std::string, std::vector, std::ifstream, std::istringstream, std::cout, std::endl;

/**
 * Creates the Sentiment analyzer class
 * @param size If no size is inputted, it defaults to 50.
 */
SentimentAnalyzer::SentimentAnalyzer(double size) {
    entries.resize(size);
    this->size = size;
    numEntries = 0;
}

/**
 * Loads words and sentiments from a file into the analyzer
 * @param input File
 * @return if the load was successful
 */
bool SentimentAnalyzer::loadLexicon(std::string input) {
    ifstream file(input);
    if (!file.is_open()) {
        return false;
    }

    string line;
    while (getline(file, line)) {
        // Because of there was no space between the comma and the sentiment, the stream took the entire line as a string
        // To make up for that, I had to make multiple substrings to make the stream work for only the sentiment
        string word = line.substr(0, line.find(','));
        istringstream num(line.substr(line.find(',') + 1, line.size()));
        int sentiment;
        num >> sentiment;

        insert(word, sentiment); // Adds word into the sentiment
    }
    cout << "Loaded " << numEntries << " words into sentiment lexicon." << endl;
    return true;
}

/**
 * Prints the general statistics of the analyzer
 */
void SentimentAnalyzer::printStats() {
    cout << "Analyzer Statistics:\n--------------------------------" << endl;
    cout << "Total Words: " << numEntries << endl;
    cout << "Table Size: " << size << endl;
    cout << "Empty Buckets: " << size - numEntries <<" (" << ((size-numEntries)/size)*100 << "%)" << endl;

    // Calculate Block Data
    int maxBlock = 0; // Highest Block
    int blocks = 0; // Individual Block Counter
    int blockCount = 0; // Number of Block Chains
    int total = 0; // Total Blocks for Average Calculation

    for (int i = 0; i < size; i++) {
        while (!entries[i].word.empty()) {
            blocks++;
            i++;
        }
        if (blocks > 1) {
            blockCount++;
            total += blocks;
        }
        if (blocks > maxBlock) {
            maxBlock = blocks;
        }
        blocks = 0;
    }

    cout << "Maximum Data Block: " << maxBlock << endl;
    cout << "Average Data Block Size: " << total/blockCount << endl;
}

/**
 * Analyzes sentiment of an inputted string based on the analyzer
 * @param line
 * @return The total sentiment
 */
double SentimentAnalyzer::analyzeSentiment(const std::string& line) {
    wordCount = 0;
    sentimentCount = 0;
    double total = 0;
    istringstream stream(line);
    string word;
    string prevWord;

    while (stream >> word) {
        if (word == "END") { // Stops reading at the word "END"
            break;
        }
        wordCount++;
        word = cleanWord(word);
        string phrase = prevWord + " " + word; // To check the previous word in case 2 words are in the analyzer
        total +=  getSentiment(word) + getSentiment(phrase);
        prevWord = word;
    }
    cout << "Words Analyzed: " << wordCount << endl;
    cout << "Words With Sentiment: " << sentimentCount << endl;
    return total;
}

/**
 * Prints stats about the inputted line and its sentiment
 * @param sentiment
 */
void SentimentAnalyzer::interpretSentiment(double sentiment) {
    double average = sentiment / wordCount; // Calculates the average
    string interpret; // Calculates the interpretation based on the average
    cout << "Overall Average: " << std::setprecision(2) << average << endl;
    if (average == -1) {
        interpret = "Very Negative";
    } else if (average > -1 && average < -0.1) {
        interpret = "Negative";
    } else if (average >= -0.1 && average <= 0.1) {
        interpret = "Neutral";
    } else if (average > 0.1 && average < 1) {
        interpret = "Positive";
    } else if (average == 1) {
        interpret = "Very Positive";
    }

    cout << "Interpretation: " << interpret << endl;
}

// Private functions

/**
 * Inserts a new entry into the analyzer
 * @param word
 * @param sentiment
 */
void SentimentAnalyzer::insert(const std::string& word, const double& sentiment) {
    if (numEntries > size/2) {
        expand();
    }

    int index = hash(word);
    bool inserted = false;

    while (!inserted) { // Using a probing technique
        if (entries[index].word.empty()) { // Checks if a word spot is empty, numbers aren't used because of the existence of sentiment: 0
            entries[index] = WordValuePair(word, sentiment);
            numEntries++;
            inserted = true;
        } else {
            index++;
            if (index >= size) { // Index loops back to the beginning if it reaches the end
                index = 0;
            }
        }
    }
}

/**
 * Expands the size of the analyzer
 */
void SentimentAnalyzer::expand() {
    vector<WordValuePair> oldEntries = std::move(entries);
    size *= 2;
    entries.resize(size);
    numEntries = 0;
    for (const auto& entry : oldEntries) {
        if (entry.sentiment != 0 && entry.word != "") {
            insert(entry.word, entry.sentiment);
        }
    }
    cout << "Rehashed " << size/2 << " -> " << size << " buckets" << endl;
}

/**
 * Hashes a word based on ACSII and analyzer size
 * @param word
 * @return index if the entry
 */
int SentimentAnalyzer::hash(const std::string& word) {
    int sum = 0;
    for (char c : word) {
        sum += static_cast<int>(c);
    }
    return sum % size;
}

/**
 * Cleans up a word be lowercasing letters and removing punctuation
 * @param word
 * @return
 */
string SentimentAnalyzer::cleanWord(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (isalpha(c)) {
            result += std::tolower(c);
        } else if (isdigit(c)) { // For inputs with numbers, since there are words in the analyzer with numbers in it
            result += c;
        }
    }
    return result;
}

/**
 * Gets the sentiment of the word, similar to the insert function
 * @param word
 * @return
 */
int SentimentAnalyzer::getSentiment(const std::string& word) {
    int index = hash(word);
    int count = 0; // Checks if the entire analyzer has been looped through
    while (count < size) {
        if (entries[index].word == word) {
            sentimentCount++;
            return entries[index].sentiment; // The word exists
        }
        index++;
        count++;
        if (index >= size) {
            index = 0;
        }
    }
    return 0; // The word doesn't exist
}