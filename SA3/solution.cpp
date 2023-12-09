#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Q1. Given two arrays arr1 and arr2, check if arr2 is a subarray of arr1

bool isSubarray(vector<int> arr1, vector<int> arr2){

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
// Can it be done in Time complexity: O(nlogk)?
int kthlargest(vector<int> arr, int k){

}

void testKthlarget(){
    vector<int> arr = {4,3,1,2};
    cout << kthlargest(arr, 1) << endl;

}
#ifndef TEST
int main(){
    testIsSubarray();
    testIsNotSubarray();
    testKthlarget();
    return 0;
}
#endif