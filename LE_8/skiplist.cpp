#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
class Node {
public:
    int key;
    std::vector<Node*> forward;

    Node(int key, int level) : key(key), forward(level + 1, nullptr) {}
};

class SkipList {
private:
    int MAXLVL;
    double P;
    Node* header;
    int level;

public:
    SkipList(int max_lvl, double p) : MAXLVL(max_lvl), P(p), level(0) {
        header = createNode(MAXLVL, -1);
    }

    Node* createNode(int lvl, int key) {
    }

    int randomLevel() {

    }

    void insertElement(int key) {
   
    }

    void deleteElement(int search_key) {


    }

    bool searchElement(int key) {

    }

    void displayList() {
        std::cout << "\n*****Skip List******" << std::endl;
        Node* head = header;
        for (int lvl = 0; lvl <= level; lvl++) {
            std::cout << "Level " << lvl << ": ";
            Node* node = head->forward[lvl];
            while (node != nullptr) {
                std::cout << node->key << " ";
                node = node->forward[lvl];
            }
            std::cout << std::endl;
        }
    }
};

void testSkipList(){
    int maxLevel = 10;
    double probability = 0.5;
    SkipList skipList(maxLevel, probability);

    skipList.insertElement(3);
    skipList.insertElement(6);
    skipList.insertElement(9);


    skipList.displayList();

    int searchKey = 3;
    skipList.searchElement(searchKey);
    skipList.deleteElement(searchKey);

    skipList.displayList();
}
#ifndef TEST
int main() {

    return 0;
}
#endif