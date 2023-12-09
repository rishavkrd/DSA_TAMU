#define TEST
#include "bst.cpp"
using namespace std;


BST_Node* createBST(){
    std::cout << "Level order traversal of the BST:" << std::endl;
    BST_Node* root = new BST_Node(5);
    root->insert(2);
    root->insert(10);
    root->insert(1);
    root->insert(3);
    root->insert(8);
    root->insert(14);
    root->insert(4);
    root->insert(7);
    root->insert(6);
    root->insert(9);
    root->insert(12);
    root->insert(16);
    root->insert(11);
    root->insert(13);
    root->insert(15);

    root->levelOrderPrint();

    return root;
}

int testFindSuccessful(BST_Node* root){
    int keyToFind = 4;
    bool found = root->find(keyToFind);
    std::cout << "Key " << keyToFind << " found: " << (found ? "Yes" : "No") << std::endl;
    if(found){
        return 1;
    }
    return 0;
}

int testFindUnsuccessful(BST_Node* root){
    int keyToFind = 17;
    bool found = root->find(keyToFind);
    std::cout << "Key " << keyToFind << " found: " << (found ? "Yes" : "No") << std::endl;
    if(found){
        return 0;
    }
    return 1;
}

int testDeleteNode(int keyToDelete, BST_Node* root){

    root = root->deleteNode(keyToDelete);
    std::cout << "After deleting key " << keyToDelete << ":" << std::endl;
    root->levelOrderPrint();
    bool found = root->find(keyToDelete);
    if(found){
        return 0;
    }
    return 1;

}

void SkewedTreeComplexity(){
    BST_Node* root = new BST_Node(1);
    for(int i = 2; i<=10000; i++){
        root->insert(i);
    }
    auto start = chrono::high_resolution_clock::now();
    root->find(10000);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout<<"Time taken: "<<duration.count()<<endl;

}
int main() {
    // Example usage of the BST_Node class
    BST_Node* root = createBST();
    int score = 0;
    score += testFindSuccessful(root);
    score += testFindUnsuccessful(root);
    score += testDeleteNode(10, root);
    SkewedTreeComplexity();

    cout<<"Score: "<<score<<"/3"<<endl;
    
    return 0;
}