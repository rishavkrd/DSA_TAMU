#include <iostream>

class BST_Node {
public:
    int key;
    BST_Node* left;
    BST_Node* right;

    // Constructor to initialize a node
    BST_Node(int key) : key(key), left(nullptr), right(nullptr) {}

    // Insert method to create nodes
    void insert(int key) {
        
    }

    // Delete method to delete nodes based on key
    BST_Node* deleteNode(int key) {
        
        return this;
    }

    // Find method to search for a key in the tree
    bool find(int lkpkey) {
        
    }

    // Print the tree in-order
    void printTree() {
        
    }

    // Helper method to find the minimum value in the tree
    int minValue() {
        
    }
};

int main() {
    // Example usage of the BST_Node class
    BST_Node* root = new BST_Node(5);
    // root->insert(3);
    // root->insert(8);
    // root->insert(2);
    // root->insert(4);

    // std::cout << "In-order traversal of the BST:" << std::endl;
    // root->printTree();

    return 0;
}
