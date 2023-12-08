// i Bubble Sort
// ii Heap Sort
// iii Merge Sort
// iv (deterministic) Quick Sort

#include <iostream>
#include <math.h>
using namespace std;

void bubbleSort(int *arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

class PriorityQueueHeap {
private:
    int *arr;
    int capacity;
    int size;
public:
    PriorityQueueHeap(){
        capacity = 100;
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

void heapSort(int *arr, int size){
    PriorityQueueHeap *pq = new PriorityQueueHeap();
    for(int i = 0; i < size; i++){
        pq->insert(arr[i]);
    }
    for(int i = 0; i < size; i++){
        arr[i] = pq->removeMin();
    }
}


void merge(int * arr, int start, int end){
    int * temp = new int[start+end];
    int mid = (start+end)/2;

    int l=start, r=mid+1, idx=0;

    while(l<=mid && r<=end){
        if(arr[l]<arr[r]){
            temp[idx++] = arr[l++];
        } else{
            temp[idx++] = arr[r++];
        }
    }
    while(l<=mid){
        temp[idx++] = arr[l++];
    }
    while(r<=end){
        temp[idx++] = arr[r++];
    }
    
    for(int i=start; i<=end; i++){
        arr[i] = temp[i-start];
    }
}

void merge_sort(int * arr, int start, int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);

    merge(arr, start, end);
}

//Quick Sort
int partition(int *arr, int start, int end){
    int pivot = arr[end];
    int i = start-1;
    for(int j = start; j < end; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}
void quick_sort(int *arr, int start, int end){
    if(start >= end){
        return;
    }
    int p = partition(arr, start, end);
    quick_sort(arr, start, p-1);
    quick_sort(arr, p+1, end);
}
