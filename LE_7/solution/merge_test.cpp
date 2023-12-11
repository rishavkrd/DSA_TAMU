//Merge sort
#define TEST
#include <iostream>
#include <thread>
#include <math.h>
#include <chrono>
#include "merge_sort.cpp"
using namespace std;

int testMergeSort(){
    int arr[] = {5,6,7,4,3,2,1,9,8,0};

    merge_sort(arr, 0, 9, 1);
    int res[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i=0; i<10; i++){
        if(arr[i] != res[i]){
            cout<<"Failed"<<endl;
            return 0;
        }
        cout<<arr[i]<<", ";
    }
    cout<<endl;
    return 1;
}

int main(){
    int out = testMergeSort();
    int time_ratio = measureTimeDifference();
    cout<<"Merge sort passing: "<<out<<endl;
    int ratioGreaterThan5 = (time_ratio>10)?1:0;
    cout<<"Time ratio of single thread to multi thread greater than 10? Passing: "<<ratioGreaterThan5<<endl;
    cout<<"Score: "<<out+ratioGreaterThan5<<"/2"<<endl;
    return 0;
}