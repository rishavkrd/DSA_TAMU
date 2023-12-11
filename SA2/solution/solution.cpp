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


int consecutiveParentChild(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftCount = 0, rightCount = 0;
    if(root->left){
        if(root->left->data == root->data + 1 || root->left->data == root->data - 1){
            cout<<root->data<<","<<root->left->data<<endl;
            leftCount = 1 + consecutiveParentChild(root->left);
        } else{
            leftCount = consecutiveParentChild(root->left);
        }
    }
    if(root->right){
        if(root->right->data == root->data + 1 || root->right->data == root->data - 1){
            cout<<root->data<<","<<root->right->data<<endl;
            rightCount = 1 + consecutiveParentChild(root->right);
        } else{
            rightCount = consecutiveParentChild(root->right);
        }
    }
    return leftCount + rightCount;

}


vector<int> reverseLevelOrder(Node* root){
    queue<Node*> q;
    stack<Node*> s;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current == NULL){
            if(!q.empty()){
                q.push(NULL);
                s.push(NULL);
            }
            continue;
        }
        s.push(current);

        if(current->right){
            q.push(current->right);
        }
        if(current->left){
            q.push(current->left);
        }

    }
    vector<int> result;
    while(!s.empty()){
        if(s.top() == NULL){
            cout <<endl;
            s.pop();
            continue;
        }
        result.push_back(s.top()->data);
        cout<<s.top()->data<<", ";
        s.pop();
    }
    return result;
}




