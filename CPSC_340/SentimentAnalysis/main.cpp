#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "SentimentAnalyzer.h"

int main() {
    SentimentAnalyzer analyzer(997); // Use a prime number for table size
    // Load lexicon
    std::string lexiconFile;
    std::cout << "Enter the sentiment lexicon filename: ";
    std::cin >> lexiconFile;
    if (!analyzer.loadLexicon(lexiconFile)) {
        std::cerr << "Failed to load lexicon. Exiting." << std::endl;
        return 1;
    }
    // Display hash table statistics
    analyzer.printStats();

    // Analysis loop
    std::cout << "\nEnter text to analyze (type 'END' to quit):" << std::endl;
    std::string line;
    std::cin.ignore(); // Clear input buffer
    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, line);
        if (line == "END") {
            break;
        }
        // Analyze sentiment
        std::cout << "\nAnalyzing: \"" << line << "\"" << std::endl;
        double sentiment = analyzer.analyzeSentiment(line);
        std::cout << "\nSentiment: " << sentiment << std::endl;
        // // Display results
        analyzer.interpretSentiment(sentiment);
    }
    std::cout << "\nThank you for using the Sentiment Analyzer!" << std::endl;
    return 0;
}