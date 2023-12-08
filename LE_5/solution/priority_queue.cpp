//Priority Queue using Min heap

#include <iostream>

using namespace std;

#ifndef PQ
#define PQ
class PriorityQueue {
private:
    int *arr;
    int capacity;
    int size;
public:
    PriorityQueue(){
        capacity = 10;
        size = 0;
        arr = new int[capacity];
    }
    int sizeOfPq(){
        return size;
    }
    bool isPqEmpty(){
        return size == 0;
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
    void pq_insert(int x){
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

    int pq_delete(){
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
#endif


