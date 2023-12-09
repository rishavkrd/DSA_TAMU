//Priority Queue using Min heap

#include <iostream>

using namespace std;

class PriorityQueue {
private:
    int *arr;
    int capacity;
    int size;
public:
    PriorityQueue(){
    }
    int sizeOfPq(){

    }
    bool isPqEmpty(){

    }
    int pq_parent(int i){

    }
    int pq_top(){

    }
    void pq_insert(int x){
        
    }
    void bubbleUp(int i){
    }

    int pq_delete(){

    }
    //Bubble Down
    void minHeapify(int i){

    }
};

void testPqInsert_Size(PriorityQueue pq, int x){
    pq.pq_insert(x);
    if(pq.pq_top() == x) {
        cout << "Insert passed" << endl;
    }
    if(pq.sizeOfPq() == 1){
        cout << "Size passed" << endl;
    }

}

#ifndef TEST
int main(){
    return 0;
}
#endif