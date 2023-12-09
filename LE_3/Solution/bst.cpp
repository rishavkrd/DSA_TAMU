#include <iostream>
#include <queue>
#include <chrono>

using namespace std;

class BST_Node {
public:
    int key;
    BST_Node* left;
    BST_Node* right;

    // Constructor to initialize a node
    BST_Node(int key){
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }

    // Insert method to create nodes
    void insert(int key) {

        if(key< this->key){
            if(this->left == nullptr){
                this->left = new BST_Node(key);
            } else{
                this->left->insert(key);
            }
        }
        else if(key>this->key){
            if(this->right == nullptr){
                this->right = new BST_Node(key);
            } else{
                this->right->insert(key);
            }
        }
    }

    // Delete method to delete nodes based on key
    BST_Node* deleteNode(int key) {

        if (key < this->key) {
            if (this->left) {
                this->left = this->left->deleteNode(key);
            }
        } else if (key > this->key) {
            if (this->right) {
                this->right = this->right->deleteNode(key);
            }
        } else {
            // Node to delete has 0 or 1 child
            if (this->left == nullptr) {
                BST_Node* temp = this->right;
                delete this;
                return temp;
            } else if (this->right == nullptr) {
                BST_Node* temp = this->left;
                delete this;
                return temp;
            }

            // Node to delete has 2 children
            // Replace the node to delete with the minimum value in the right subtree
            int minVal = this->right->minValue();
            this->key = minVal;
            this->right = this->right->deleteNode(minVal);
        }
        return this;
    }

    // Helper method to find the minimum value in the tree
    int minValue() {
        if (this->left == nullptr) {
            return this->key;
        } else {
            return this->left->minValue();
        }
    }
    // Find method to search for a key in the tree
    bool find(int lkpkey) {
        if (lkpkey < this->key) {
            if (this->left == nullptr) {
                return false;
            }
            return this->left->find(lkpkey);
        } else if (lkpkey > this->key) {
            if (this->right == nullptr) {
                return false;
            }
            return this->right->find(lkpkey);
        } else {
            return true;
        }
    }

    // Print the tree in-order
    void printTree() {
        if (this->left) {
            this->left->printTree();
        }
        std::cout << this->key << std::endl;
        if (this->right) {
            this->right->printTree();
        }
    }

    void levelOrderPrint(){
        queue<BST_Node*> q;
        q.push(this);
        q.push(nullptr);

        while(!q.empty()){
            BST_Node* curr = q.front();
            q.pop();

            if(curr == nullptr){
                if(!q.empty()){
                    q.push(nullptr);
                }
                cout<<endl;
                continue;
            }
            cout<<curr->key<<"\t";
            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }
        }

    }

};

#ifndef TEST
int main() {
    
    return 0;
}
#endif
