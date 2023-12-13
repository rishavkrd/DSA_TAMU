#define TEST
#include "sort.cpp"
int main(){
    
    
    int n = 20;
    int arr1[] = {64, 36, 58, 67, 69, 45, 62, 41, 81, 27, 24, 34, 78, 61, 95, 0, 5, 42, 27, 91};
    int sorted[] = {0, 5, 24, 27, 27, 34, 36, 41, 42, 45, 58, 61, 62, 64, 67, 69, 78, 81, 91, 95};
    int *arr2 = new int[n];
    int *arr3 = new int[n];
    int *arr4 = new int[n];

    for(int i=0; i<n; i++){
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
    cout << "Bubble Sort" << endl;
    bubbleSort(arr1, n);
    int bubbleScore = 1;
    for(int i=0; i<n; i++){
        cout << arr1[i] << " ";
        if(arr1[i] != sorted[i]){
            cout << "Bubble Sort Failed" << endl;
            bubbleScore = 0;
        }
    }
    cout << endl;

    cout << "Heap Sort" << endl;
    heapSort(arr2, n);
    int heapScore = 1;
    for(int i=0; i<n; i++){
        cout << arr2[i] << " ";
        if(arr2[i] != sorted[i]){
            cout << "Heap Sort Failed" << endl;
            heapScore = 0;
        }
    }
    cout << endl;

    cout << "Merge Sort" << endl;
    merge_sort(arr3, 0, n-1);
    int mergeScore = 1;
    for(int i=0; i<n; i++){
        cout << arr3[i] << " ";
        if(arr3[i] != sorted[i]){
            cout << "Merge Sort Failed" << endl;
            mergeScore = 0;
        }
    }
    cout << endl;

    cout << "Quick Sort" << endl;
    quick_sort(arr4, 0, n-1);
    int quickScore = 1;
    for(int i=0; i<n; i++){
        cout << arr4[i] << " ";
        if(arr4[i] != sorted[i]){
            cout << "Quick Sort Failed" << endl;
            quickScore = 0;
        }
    }
    cout << endl;

    cout << "Total Score: "<< bubbleScore + heapScore + mergeScore + quickScore << "/4" << endl;
    return 0;
}