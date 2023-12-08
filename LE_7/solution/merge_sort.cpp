//Merge sort

#include <iostream>
#include <thread>
#include <math.h>
#include <chrono>
using namespace std;

int MAX_THREAD = 4;

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

void merge_sort(int * arr, int start, int end, int level){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;

    if(pow(level,2)<MAX_THREAD){
        thread t1(merge_sort, arr, start, mid, level+1);
        thread t2(merge_sort, arr, mid+1, end, level+1);
        t1.join();
        t2.join();
    } else{
        merge_sort(arr, start, mid, level+1);
        merge_sort(arr, mid+1, end, level+1);
    }


    merge(arr, start, end);
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


