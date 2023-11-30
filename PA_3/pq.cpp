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
            this->capacity = capacity;
            this->size = 0;
            this->arr = new int[capacity];
        }
        ~UnsortedPriorityQueue(){
            delete[] arr;
        }
        void insert(int value){
            if(size == capacity){
                cout<<"Queue is full"<<endl;
                return;
            }
            arr[size] = value;
            size++;
        }
        int removeMin(){
            if(size == 0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int min = arr[0];
            int minIndex = 0;
            for(int i = 1; i < size; i++){
                if(arr[i] < min){
                    min = arr[i];
                    minIndex = i;
                }
            }
            arr[minIndex] = arr[size-1];
            size--;
            return min;
        }
        int getSize(){
            return size;
        }
};

class SortedPriorityQueue : public AbstractPriorityQueue{
    private:
        int *arr;
        int size;
        int capacity;
    public:
        SortedPriorityQueue(int capacity=100){
            this->capacity = capacity;
            this->size = 0;
            this->arr = new int[capacity];
        }
        ~SortedPriorityQueue(){
            delete[] arr;
        }
        void insert(int value){
            if(size == capacity){
                cout<<"Queue is full"<<endl;
                return;
            }
            int i = size-1;
            while(i >= 0 && arr[i] > value){
                arr[i+1] = arr[i];
                i--;
            }
            arr[i+1] = value;
            size++;
        }
        int removeMin(){
            if(size == 0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int min = arr[0];
            for(int i = 1; i < size; i++){
                arr[i-1] = arr[i];
            }
            size--;
            return min;
        }
        int getSize(){
            return size;
        }
};


class PriorityQueueHeap : public AbstractPriorityQueue {
private:
    int *arr;
    int capacity;
    int size;
public:
    PriorityQueueHeap(){
        capacity = 10;
        size = 0;
        arr = new int[capacity];
    }
    int getSize(){
        return size;
    }
    int pq_parent(int i){
        return (i-1)/2;
    }
    int pq_top(){
        if(size == 0){
            cout << "Underflow" << endl;
            return -1;
        }
        return arr[0];
    }
    void insert(int x){
        if(size == capacity){
            cout << "Overflow" << endl;
            return;
        }
        size++;
        arr[size-1] = x;
        int i = size-1;
        bubbleUp(i);
        
    }
    void bubbleUp(int i){
        if(i == 0){
            return;
        }
        int p = pq_parent(i);
        if(arr[p] > arr[i]){
            swap(arr[p], arr[i]);
            bubbleUp(p);
        }
    }

    int removeMin(){
        if(size == 0){
            cout << "Underflow" << endl;
            return -1;
        }
        int x = arr[0];
        arr[0] = arr[size-1];
        size--;
        minHeapify(0);
        return x;
    }
    //Bubble Down
    void minHeapify(int i){
        int l = 2*i+1;
        int r = 2*i+2;
        int smallest = i;
        if(l < size && arr[l] < arr[i]){
            smallest = l;
        }
        if(r < size && arr[r] < arr[smallest]){
            smallest = r;
        }
        if(smallest != i){
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }
};

bool testInsert(AbstractPriorityQueue *pq, vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        pq->insert(v[i]);
    }
    return pq->getSize() == v.size();
}
bool testRemoveMin(AbstractPriorityQueue *pq, vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        if(pq->removeMin() != v[i]){
            return false;
        }
    }
    return true;
}

int main(){

    vector<int> v = {1, 2, 3, 4, 5};
    AbstractPriorityQueue *pq = new UnsortedPriorityQueue();
    cout<<"Test Insert Unsorted: "<<testInsert(pq, v)<<endl;
    cout<<"Test RemoveMin Unsorted: "<<testRemoveMin(pq, v)<<endl;
    
    AbstractPriorityQueue *pq2 = new SortedPriorityQueue();
    cout<<"Test Insert Sorted: "<<testInsert(pq2, v)<<endl;
    cout<<"Test RemoveMin Sorted: "<<testRemoveMin(pq2, v)<<endl;

    AbstractPriorityQueue *pq3 = new PriorityQueueHeap();
    cout<<"Test Insert Heap: "<<testInsert(pq3, v)<<endl;
    cout<<"Test RemoveMin Heap: "<<testRemoveMin(pq3, v)<<endl;
    return 0;

}



