//Create 3 Priority Queues
// 1. Unsorted Priority Queue using List
// 2. Sorted Priority Queue using List
// 3. Sorted Priority Queue using Array

#include <iostream>
#include <vector>
using namespace std;

class AbstractPriorityQueue{
    public:
        virtual void insert(int value) = 0;
        virtual int removeMin() = 0;
        virtual int getSize() = 0;
};

class UnsortedPriorityQueue : public AbstractPriorityQueue{
    private:
        int *arr;
        int size;
        int capacity;
    public:
        UnsortedPriorityQueue(int capacity=100){
        }
        ~UnsortedPriorityQueue(){
            delete[] arr;
        }
        void insert(int value){

        }
        int removeMin(){

        }
        int getSize(){

        }
};

class SortedPriorityQueue : public AbstractPriorityQueue{
    
};


class PriorityQueueHeap : public AbstractPriorityQueue {

};
#ifndef TEST
int main(){

    vector<int> v = {1, 2, 3, 4, 5};
    AbstractPriorityQueue *pq = new UnsortedPriorityQueue();
    cout<<"Test Insert Unsorted: "<<endl;
    cout<<"Test RemoveMin Unsorted: "<<endl;
    
    AbstractPriorityQueue *pq2 = new SortedPriorityQueue();
    cout<<"Test Insert Sorted: "<<endl;
    cout<<"Test RemoveMin Sorted: "<<endl;

    AbstractPriorityQueue *pq3 = new PriorityQueueHeap();
    cout<<"Test Insert Heap: "<<endl;
    cout<<"Test RemoveMin Heap: "<<endl;
    return 0;

}

#endif

