#define TEST
#include "skiplist.cpp"
int testSkipList(){
    int score = 0;
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

    int vec[] = {2, 3, 4, 5, 6, 8, 9};
    for (int i = 0; i < 7; i++) {
        int searchKey = vec[i];
        if(!skipList.searchElement(searchKey)){
            score = 0;
        } else{
            score++;
        }
    }
    if (score == 7){
        cout<< "Insertion passed!" << endl;
        score = 1;
    } else{
        cout<< "Insertion failed!" << endl;
        score = 0;
    }

    int searchKey = 8;
    score += skipList.searchElement(searchKey);

    int deleteKey = 6;
    skipList.deleteElement(deleteKey);
    score += skipList.searchElement(deleteKey)==0?1:0;

    skipList.displayList();
    return score;
}

int main() {
    int score = testSkipList();
    cout<< "Score : " << score << "/3"<< endl;
    return 0;
}