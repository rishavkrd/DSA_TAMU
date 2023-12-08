#define TEST
#include <iostream>
#include "priority_queue.cpp"
using namespace std;

int testPqInsert_Size(PriorityQueue pq, int x){
    int score = 0;
    pq.pq_insert(x);
    if(pq.pq_top() == x) {
        cout << "Insert passed" << endl;
        score++;
    }
    if(pq.sizeOfPq() == 1){
        cout << "Size passed" << endl;
        score++;
    }
    return score;

}
 int testPqDelete(PriorityQueue pq, int x){
     int score = 0;
     pq.pq_insert(x);
     if(pq.pq_delete() == x){
         cout << "Delete passed" << endl;
         score++;
     }
     pq.pq_insert(1);
     pq.pq_insert(2);
     pq.pq_insert(3);
     pq.pq_insert(4);
     if(pq.sizeOfPq() == 4){
         cout << "Size 4 passed" << endl;
         score++;
     }
     pq.pq_delete();
     pq.pq_delete();
     pq.pq_delete();
     pq.pq_delete();
     if(pq.sizeOfPq() == 0){
        cout << "Size 0 passed" << endl;
        score++;
     }
     return score;
 }

int main(){
    PriorityQueue pq;
    int score = 0;
    score+=testPqInsert_Size(pq, 10);
    score+=testPqDelete(pq, 10);
    cout << "Score: " << score << "/5" << endl;
    return 0;
}