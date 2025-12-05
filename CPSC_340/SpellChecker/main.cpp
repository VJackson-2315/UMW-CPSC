#include <iostream>
#include <string>
#include "BST.h"

int main() {
    // Create a new BST
    BinarySearchTree bst;
    // Load words from file directly into the BST
    std::string filename = "words.txt";
    if (bst.loadFromFile(filename)) {
        // Display the tree contents if loading was successful
        // bst.display();
    } else {
        std::cerr << "Failed to build tree from file." << std::endl;
    }
    bst.spellCheck();

    return 0;
}
