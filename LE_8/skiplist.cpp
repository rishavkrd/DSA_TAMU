#include <iostream>
#include <vector>
#include <cstdlib>

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
        return new Node(key, lvl);
    }

    int randomLevel() {
        int lvl = 0;
        while (static_cast<double>(rand()) / RAND_MAX < P && lvl < MAXLVL) {
            lvl++;
        }
        return lvl;
    }

    void insertElement(int key) {
        std::vector<Node*> update(MAXLVL + 1, nullptr);
        Node* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (!current || current->key != key) {
            int rlevel = randomLevel();

            if (rlevel > level) {
                for (int i = level + 1; i <= rlevel; i++) {
                    update[i] = header;
                }
                level = rlevel;
            }

            Node* n = createNode(rlevel, key);

            for (int i = 0; i <= rlevel; i++) {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }

            std::cout << "Successfully inserted key " << key << std::endl;
        }
    }

    void deleteElement(int search_key) {
        std::vector<Node*> update(MAXLVL + 1, nullptr);
        Node* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < search_key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current && current->key == search_key) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != current) {
                    break;
                }
                update[i]->forward[i] = current->forward[i];
            }

            while (level > 0 && header->forward[level] == nullptr) {
                level--;
            }

            std::cout << "Successfully deleted " << search_key << std::endl;
            delete current;
        }
    }

    void searchElement(int key) {
        Node* current = header;
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
        }

        current = current->forward[0];

        if (current && current->key == key) {
            std::cout << "Key " << key << " found in the Skip List." << std::endl;
        } else {
            std::cout << "Key " << key << " not found in the Skip List." << std::endl;
        }
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
    skipList.insertElement(2);
    skipList.insertElement(8);
    skipList.insertElement(4);
    skipList.insertElement(5);

    skipList.displayList();

    int searchKey = 8;
    skipList.searchElement(searchKey);

    int deleteKey = 6;
    skipList.deleteElement(deleteKey);

    skipList.displayList();
}

int main() {
    testSkipList();

    return 0;
}