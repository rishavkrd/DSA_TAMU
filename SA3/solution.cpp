#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Q1. Given two arrays arr1 and arr2, check if arr2 is a subarray of arr1

bool isSubarray(vector<int> arr1, vector<int> arr2){
    int hash[100000] = {0};
    for(int i : arr2){
        hash[i]++;
    }
    for(int i : arr1){
        hash[i]--;
    }
    for(int i=0; i<100000; i++){
        if(hash[i] > 0){
            return false;
        }
    }
    return true;
}

void testIsSubarray(){
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {2, 3, 4};
    cout << isSubarray(arr1, arr2) << endl;
}
void testIsNotSubarray(){
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {2, 3, 7};
    cout << isSubarray(arr1, arr2) << endl;
}

// Q2. Kth largest element in an unsorted array.
// Time complexity: O(nlogk)
int kthlargest(vector<int> arr, int k){
    priority_queue<int, vector<int>, greater<int>> minheap;
    int i;
    for( i=0; i<k; i++){
        minheap.push(arr[i]);
    }
    for(; i<arr.size(); i++){
        if(arr[i]>minheap.top()){
            minheap.pop();
            minheap.push(arr[i]);
        }
    }
    return minheap.top();
}

void testKthlargetIs5(){
    vector<int> arr = {4,3,1,2,6,7,9,5,8,10};
    cout << kthlargest(arr, 6) << endl;
    arr = {4,3,1,2,6,7,9,5,8,10,11,12,13,14,15};
    cout << kthlargest(arr, 11) << endl;
}

int main(){
    testIsSubarray();
    testIsNotSubarray();
    testKthlargetIs5();
    return 0;
}