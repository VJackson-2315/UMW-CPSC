#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::string, std::ifstream, std::stringstream, std::istringstream, std::getline, std::cin, std::cout, std::endl;

/**
 * Traverses through the Tree in-order
 * @param node
 */
void BinarySearchTree::inOrderTraversalRecursive(Node* node) {
    if (node != nullptr) {
        inOrderTraversalRecursive(node->left);
        cout << node->data << endl;
        inOrderTraversalRecursive(node->right);
    }
}

/**
 * Deletes the Tree
 */
BinarySearchTree::~BinarySearchTree() {
    // Calls deleteNode at the root
    // I created that function to prevent myself from creating a loop
    deleteNodeRecursive(root);
}

/**
 * Deletes every node below a certain starting node
 * @param node
 */
void BinarySearchTree::deleteNodeRecursive(Node *node) {
    if (node != nullptr) { // Only runs if the node isn't null
        if (node->left == nullptr && node->right == nullptr) { // If the node doesn't have children
            delete node;
        } // If the node has children
        deleteNodeRecursive(node->left); // Check on the left
        deleteNodeRecursive(node->right); // Check on the right
    }
}

/**
 * Creates a Tree from a file
 * @param filename
 * @return if the file was successfully loaded into the tree
 */
bool BinarySearchTree::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << endl;
        return false;
    }
    string word;
    int insertCount = 0;
    while (getline(file, word)) {
        this->insert(word);
        insertCount++;
    }
    file.close();
    cout << "Loaded the words into a tree with height = " << getHeight(root) << endl;
    return true;
}

/**
 * Prints out each of the tree's contents in order
 */
void BinarySearchTree::display() {
    cout << "Tree contents (in-order): ";
    inOrderTraversalRecursive(root);
    cout << endl;
}

/**
 * Inserts a value into a tree
 * @param value
 */
void BinarySearchTree::insert(string value) { //Takes a value
    root = insertRecursive(root, value);
}

/**
 * Creates a node from an inserted value based on values from the current node
 * @param current Location of traversal
 * @param value
 * @return new node
 */
Node* BinarySearchTree::insertRecursive(Node* current, string value) {
    // If we've reached an empty spot, create a new node there
    if (current == nullptr) {
        return new Node(value);
    }
    // Determine whether to insert in the left or right subtree
    if (value < current->data) {
        current->left = insertRecursive(current->left, value);
    } else if (value > current->data) {
        current->right = insertRecursive(current->right, value);
    }
    // If value equals current->data, we're ignoring duplicates
    return current;
}

/**
 * Calculates and returns the height of a tree
 * @param node Starting node
 * @return Height of the tree
 */
int BinarySearchTree::getHeight(Node* node) {
    if (node == nullptr) { // If the node doesn't exist
        return 0;
    }
    if (node->right == nullptr && node->left == nullptr) { // If the node has no children
        return 1;
    }

    // Check and calculate the heights for both the left and right children of the node
    // The + 1 is to calculate the level of the node
    int leftHeight = getHeight(node->left) + 1;
    int rightHeight = getHeight(node->right) + 1;

    // If the heights are equal, then it returns the shared height
    if (leftHeight >= rightHeight) { //
        return leftHeight;
    } if (leftHeight <= rightHeight) {
        return rightHeight;
    }
}

// Spell Checker Exclusive Functions
/**
 * Checks if an inputted line was spelled correctly
 */
void BinarySearchTree::spellCheck() {
    string line;
    while (getline(cin, line)) {
        if (line == "END") {
            return;
        }
        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordSearch(word, root);
        }
    }
}

/**
 * Checks if a word was spelled correctly
 * @param word
 * @param node
 * @return if the word was spelled correctly
 */
bool BinarySearchTree::wordSearch(string word, Node* node) {
    if (node != nullptr) {
        if (word == node->data) {
            return true;
        }
        if (word < node->data) {
            return wordSearch(word, node->left);
        }
        if (word > node->data) {
            return wordSearch(word, node->right);
        }
    }
    cout << word << " is spelled wrong!" << endl;
    return false;
}