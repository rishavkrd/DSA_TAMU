// i Bubble Sort
// ii Heap Sort
// iii Merge Sort
// iv (deterministic) Quick Sort

#include <iostream>
#include <math.h>
using namespace std;

void bubbleSort(int *arr, int size){
    
}

class PriorityQueueHeap {
private:
    int *arr;
    int capacity;
    int size;
public:
    PriorityQueueHeap(){
    }
    int getSize(){

    }

    int pq_top(){

    }
    void insert(int x){

        
    }
    void bubbleUp(int i){

    }

    int removeMin(){

    }
    //Bubble Down
    void minHeapify(int i){

    }
};

void heapSort(int *arr, int size){
    
}


void merge(int * arr, int start, int end){
    
}

void merge_sort(int * arr, int start, int end){
    
}

//Quick Sort
int partition(int *arr, int start, int end){
    
}
void quick_sort(int *arr, int start, int end){
    
}
#ifndef TEST
int main(){
    int n = 20;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int *arr3 = new int[n];
    int *arr4 = new int[n];

    for(int i=0; i<n; i++){
        arr1[i] = rand()%100;
        arr2[i] = rand()%100;
        arr3[i] = rand()%100;
        arr4[i] = rand()%100;
    }
    cout << "Bubble Sort" << endl;
    bubbleSort(arr1, n);
    for(int i=0; i<n; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Heap Sort" << endl;
    heapSort(arr2, n);
    for(int i=0; i<n; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Merge Sort" << endl;
    merge_sort(arr3, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;

    cout << "Quick Sort" << endl;
    quick_sort(arr4, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr4[i] << " ";
    }
    cout << endl;
    return 0;
}
#endif