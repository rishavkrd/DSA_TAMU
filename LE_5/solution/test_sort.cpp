#include <iostream>
#define TEST
#include "sort.cpp"
#include "priority_queue.cpp"

using namespace std;

// [170, 90, 802, 2, 24, 45, 75, 66]


void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int testRadixSort(int *arr, int n){
    cout << "Radix Sort: " << endl;
    radixSort(arr, n);
    printArray(arr, n);
    int res[] = {2, 24, 45, 66, 75, 90, 170, 802};
    for(int i=0; i<n; i++){
        if(arr[i] != res[i]){
            cout << "Failed" << endl;
            return 0;
        }
    }
    return 1;
}

int testInsertionSort(int *arr, int n){
    cout << "Insertion Sort: " << endl;
    insertion_sort(arr, n);
    printArray(arr, n);
    int res[] = {2, 24, 45, 66, 75, 90, 170, 802};
    for(int i=0; i<n; i++){
        if(arr[i] != res[i]){
            cout << "Failed" << endl;
            return 0;
        }
    }
    return 1;
}

int main(){
    int arr[] = {170, 90, 802, 2, 24, 45, 75, 66};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Array: " << endl;
    printArray(arr, n);
    int out = testRadixSort(arr, n);
    cout<<"Radix Sort passing: "<<out<<endl;
    int out2 = testInsertionSort(arr, n);
    cout<<"Insertion Sort passing: "<<out2<<endl;

    cout<<"Score: "<<out+out2<<"/2"<<endl;
    return 0;
}