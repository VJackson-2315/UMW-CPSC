// Tori Jackson
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

// Helper function to clean a word (remove punctuation, convert to lowercase)
std::string cleanWord(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (isalpha(c)) {
            result += std::tolower(c);
        }
    }
    return result;
}

int main() {
    // Open the input file (use a text file with substantial content)
    std::ifstream file("sample_text.txt"); // You'll need to provide this file
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    // Count word frequencies using unordered_map
    std::unordered_map<std::string, int> wordFrequency;
    std::string word;

    while (file >> word) {
        std::string cleaned = cleanWord(word);
        if (!cleaned.empty()) {
            // TODO: Increment the frequency count for this word
            wordFrequency[cleaned]++;
        }
    }

    // Stop timing
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Find the most frequent words
    std::vector<std::pair<std::string, int>> wordFreqVector;

    // TODO: Convert the unordered_map to a vector of pairs
    // HINT: Find a way to loop through the unordered_map and push_back to the vector
    for (const auto& pair : wordFrequency) {
        wordFreqVector.push_back(pair);
    }

    // TODO: Sort the vector by frequency (highest first)
    // HINT: Use std::sort
    // Your code here
    auto compare = [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
        return a.second > b.second;
        // Got the function from Geeks for Geeks
        // https://www.geeksforgeeks.org/cpp/sort-vector-of-pairs-in-ascending-order-in-c/
    };

    std::sort(wordFreqVector.begin(), wordFreqVector.end(), compare);

    // Print the top 10 most frequent words
    std::cout << "Top 10 most frequent words:\n";
    int count = 0;
    for (const auto& pair : wordFreqVector) {
        if (count++ >= 10) break;
        std::cout << pair.first << ": " << pair.second << " occurrences\n";
    }

    std::cout << "\nProcessed in " << duration.count() << " milliseconds\n";
    std::cout << "Total unique words: " << wordFrequency.size() << "\n";
    std::cout << "Load factor: " << wordFrequency.load_factor() << "\n";

    return 0;
}