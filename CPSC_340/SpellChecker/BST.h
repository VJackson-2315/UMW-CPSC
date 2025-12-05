#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>

using std::string, std::cin;

// Define the structure for a BST node
struct Node {
    string data;
    Node* left;
    Node* right;
    // Constructor to create a new node with the given value
    Node(string value) : data(value), left(nullptr), right(nullptr) {}
};
// Binary Search Tree class
class BinarySearchTree {
public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}
    // Destructor
    ~BinarySearchTree();
    // Public method to insert a value into the tree
    void insert(string value);
    // Public method to display the tree (in-order)
    void display();
    // Member function to load and insert multiple values from a file
    bool loadFromFile(const std::string& filename);

    void spellCheck();

private:
    Node* root;
    // Private helper method for inserting a value into the tree
    Node* insertRecursive(Node* current, string value);
    // Private helper method for displaying the tree (in-order traversal)
    void inOrderTraversalRecursive(Node* node);
    void deleteNodeRecursive(Node* node);

    int getHeight(Node* node);
    bool wordSearch(string word, Node* node);
};
#endif //BST_H
