//Merge sort

#include <iostream>
#include <thread>
#include <math.h>
#include <chrono>
using namespace std;

int MAX_THREAD = 4;

void merge(int * arr, int start, int end){
    
}

void merge_sort(int * arr, int start, int end, int level){
    
}

int measure(int *arr, int n, int level){
    auto start = chrono::high_resolution_clock::now();
    merge_sort(arr, 0, n-1, level);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout<<"Time taken: "<<duration.count()<<endl;
    return duration.count();
    
}

int measureTimeDifference(){
    int n = 20;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        arr[i] = i;
    }
    cout<<"Single Thread"<<endl;
    int single_thread_time = measure(arr, n, 1);
    delete[] arr;
    

    arr = new int[n];
    for(int i=0; i<n; i++){
        arr[i] = i;
    }
    cout<<"Multi Thread"<<endl;
    int multithread_time = measure(arr, n, 5);
    delete[] arr;

    return single_thread_time/ multithread_time;
}


#ifndef TEST
int main(){
    measureTimeDifference();
    return 0;
}
#endif