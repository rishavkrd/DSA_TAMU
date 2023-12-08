#define TEST
#include "solution.cpp"

using namespace std;

// Q1. Given two arrays arr1 and arr2, check if arr2 is a subarray of arr1

int testIsSubarray(){
    int score = 0;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {2, 3, 4};
    if(isSubarray(arr1, arr2)){
        score += 1;
    } else{
        cout<<"Test Is Subarray: Failed"<<endl;
        return 0;
    }
    return score;
    
}
int testIsNotSubarray(){
    int score = 0;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {2, 3, 7};
    if(!isSubarray(arr1, arr2)){
        score += 1;
    } else{
        cout<<"Test Is Not Subarray: Failed"<<endl;
        return 0;
    }
    return score;
}

// Q2. Kth largest element in an unsorted array.
// Time complexity: O(nlogk)


int testKthlargetIs5(){
    int score = 0;
    vector<int> arr = {4,3,1,2,6,7,9,5,8,10};
    cout << kthlargest(arr, 6) << endl;
    if(kthlargest(arr, 6) == 5){
        score += 1;
    } else{
        cout<<"Test Kth Largest: Failed"<<endl;
        return 0;
    }
    arr = {4,3,1,2,6,7,9,5,8,10,11,12,13,14,15};
    if(kthlargest(arr, 11) == 5){
        score += 1;
    } else{
        cout<<"Test Kth Largest: Failed"<<endl;
        return 0;
    }
    cout << kthlargest(arr, 11) << endl;
    return score;
}

int main(){
    int score = 0;
    score+= testIsSubarray();
    score+= testIsNotSubarray();
    score+= testKthlargetIs5();
    cout<<"Total Score: "<<score<<"/4"<<endl;
    return 0;
}