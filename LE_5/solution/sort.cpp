#include <iostream>
#include "priority_queue.cpp"

using namespace std;

// [170, 90, 802, 2, 24, 45, 75, 66]

int maxDigits(int* arr, int n){
    int maxNum = arr[0];
    for(int i=0; i<n ; i++){
        maxNum = max(arr[i], maxNum);
    }
    int digits = 0;

    while(maxNum >0){
        digits++;
        maxNum /= 10;
    }
    return digits;
}

void countSort(int *arr, int n, int exp){
    int *output = new int[n];
    int i, count[10] = {0};

    for(int i=0; i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1; i<10;i++){
        count[i] += count[i-1];
    }
    for(int i=n-1; i>=0; i--){
        int digit = (arr[i]/exp)%10;
        output[count[digit] - 1] = arr[i];
        count[(digit)]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

int* radixSort(int *arr, int n){
    int digits = maxDigits(arr, n);
    int exp = 1;
    for(int i=0; i<digits; i++){
        countSort(arr, n, exp);
        exp *= 10;
    }
    return arr;
}


int* insertion_sort(int *arr, int n){
    PriorityQueue pq;
    for(int i=0; i<n; i++){
        pq.pq_insert(arr[i]);
    }
    for(int i=0; i<n;i++){
        arr[i] = pq.pq_delete();
    }
    return arr;
}
