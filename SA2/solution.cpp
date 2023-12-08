#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        Node * left, * right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createTree(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return root;
}

int consecutiveParentChild(Node* root){


}

void testConsecutiveParentChild(){
    cout<<"Question 1"<<endl;
    Node* root = createTree();
    int pairs = consecutiveParentChild(root);
    cout<<"Total Consecutive Parent, Child pairs: "<<pairs<<endl;
}

vector<int> reverseLevelOrder(Node* root){
    
}

void testReverseLevelOrder(){
    cout<<endl<<"Question 2"<<endl;
    Node* root = createTree();
    vector<int> result = reverseLevelOrder(root);
    cout<<endl<<"Result :"<<endl;
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<", ";
    }
    cout<<endl;
}
#ifndef TEST
int main(){
    testConsecutiveParentChild();
    testReverseLevelOrder();
    return 0;
}
#endif
