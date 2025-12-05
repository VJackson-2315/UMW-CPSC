//
// Created by Victoria Jackson on 11/15/2025.
//

#ifndef SENTIMENTANALYSIS_SENTIMENTANALYZER_H
#define SENTIMENTANALYSIS_SENTIMENTANALYZER_H

#include <string>
#include <vector>

struct WordValuePair {
    std::string word;
    int sentiment;
    WordValuePair() : sentiment(0) {}
    WordValuePair(const std::string& w, const int& sentiment) : word(w), sentiment(sentiment) {}
};

class SentimentAnalyzer {
public:
    SentimentAnalyzer(double size = 50);
    ~SentimentAnalyzer() = default;

    bool loadLexicon(std::string input);
    double analyzeSentiment(const std::string& line);
    void interpretSentiment(double sentiment);
    void printStats();


private:
    void insert(const std::string& word, const double& sentiment);
    int hash(const std::string& word);
    void expand();
    std::string cleanWord(const std::string& word);
    int getSentiment(const std::string& word);

    std::vector<WordValuePair> entries;
    int wordCount; // wordCount and sentimentCount exist so I don't make copies and can use them for interpretation
    int sentimentCount;
    int size;
    double numEntries;
};


#endif //SENTIMENTANALYSIS_SENTIMENTANALYZER_H