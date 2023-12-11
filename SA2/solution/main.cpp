#define TEST
#include "solution.cpp"
using namespace std;

Node* createTree(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);
    return root;
}
Node* createTree2(){

    Node* root = new Node(16);
    root->left = new Node(17);
    root->right = new Node(30);
    root->left->left = new Node(18);
    root->left->right = new Node(25);
    root->right->left = new Node(87);
    root->right->right = new Node(31);
    root->left->left->left = new Node(45);
    root->left->left->right = new Node(19);
    root->left->right->left = new Node(26);
    root->left->right->right = new Node(90);
    root->right->left->left = new Node(76);
    root->right->left->right = new Node(66);
    root->right->right->left = new Node(27);
    root->right->right->right = new Node(32);

    return root;
}

int testConsecutiveParentChild(){
    cout<<"Question 1"<<endl;
    int score = 0;
    Node* root = createTree();
    int pairs = consecutiveParentChild(root);
    cout<<"Total Consecutive Parent, Child pairs: "<<pairs<<endl;
    if(pairs == 3){
        score += 1;
    } else{
        cout<<"Test Consecutive Parent Child: Failed"<<endl;
        return 0;
    }
    Node* root2 = createTree2();
    pairs = consecutiveParentChild(root2);
    cout<<"Total Consecutive Parent, Child pairs: "<<pairs<<endl;
    if(pairs == 6){
        score += 1;
    } else{
        cout<<"Test Consecutive Parent Child: Failed"<<endl;
        return 0;
    }
    return score;
}

int testReverseLevelOrder(){
    cout<<endl<<"Question 2"<<endl;
    Node* root = createTree();
    vector<int> result = reverseLevelOrder(root);
    cout<<endl<<"Result :"<<endl;
    int res[] = {6,7,4,5,2,3,1};
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<", ";
        if(result[i] != res[i]){
            cout<<"Test Reverse Level Order: Failed"<<endl;
            return 0;
        }
    }
    cout<<endl;
    return 1;
}
int main(){
    int score = 0;
    score += testConsecutiveParentChild();
    score += testReverseLevelOrder();
    cout<<"Total Score: "<<score<<"/3"<<endl;
    return 0;
}