#include <iostream>
#include <vector>

using namespace std;

// Linear Search: O(n) time complexity
int linear_search(const vector<int>& lis_arr, int target) {
    for (int i = 0; i < lis_arr.size(); i++) {
        if (lis_arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int find_max(const vector<int>& lis_arr) {
    int max = 0;
    // Find Max: O(n) time complexity
    for (int i = 0; i < lis_arr.size(); i++) {
        if (max < lis_arr[i]) {
            max = lis_arr[i];
        }
    }
    return max;
}

// Binary Search: O(log n) time complexity (for sorted arrays)
int binary_search(const vector<int>& lis_arr, int target, int low = 0, int high = -1) {
    if (high == -1) {
        high = lis_arr.size() - 1;
    }

    if (high < low) {
        return -1;
    }
    int midpoint = (low + high) / 2;

    if (lis_arr[midpoint] == target) {
        return midpoint;
    } else if (target < lis_arr[midpoint]) {
        return binary_search(lis_arr, target, low, midpoint - 1);
    } else {
        return binary_search(lis_arr, target, midpoint + 1, high);
    }
}

void bubble_sort(vector<int>& lis_arr) {
    // Bubble Sort: O(n^2) time complexity
    for (int i = 0; i < lis_arr.size(); i++) {
        bool swapped = false;
        for (int j = 0; j < lis_arr.size() - i - 1; j++) {
            if (lis_arr[j] > lis_arr[j + 1]) {
                swap(lis_arr[j], lis_arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

bool duplicate(const vector<int>& lis_arr) {
    for (int i = 0; i < lis_arr.size(); i++) {
        for (int j = 0; j < lis_arr.size(); j++) {
            if (i == j) {
                continue;
            } else {
                if (lis_arr[i] == lis_arr[j]) {
                    return true;
                }
            }
        }
    }
    return false;
}

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> output;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            output.push_back(left[i]);
            i++;
        } else {
            output.push_back(right[j]);
            j++;
        }
    }
    output.insert(output.end(), left.begin() + i, left.end());
    output.insert(output.end(), right.begin() + j, right.end());
    return output;
}

vector<int> merge_sort(vector<int> lis_arr) {
    int list_length = lis_arr.size();
    if (list_length == 1) {
        return lis_arr;
    } else {
        int mid_point = list_length / 2;
        vector<int> left_partition(lis_arr.begin(), lis_arr.begin() + mid_point);
        vector<int> right_partition(lis_arr.begin() + mid_point, lis_arr.end());
        left_partition = merge_sort(left_partition);
        right_partition = merge_sort(right_partition);
        return merge(left_partition, right_partition);
    }
}

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    if (n > 2) {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    return 0; // Handle invalid input
}

// Note: Powerset functions are not implemented here.

int main() {
    vector<int> x = {1, 3, 5, 10, 12};
    int target = 3;
    int result = linear_search(x, target);
    cout << "Linear Search Result: " << result << endl;

    x = {6, 5, 12, 10, 9, 1};
    bubble_sort(x);
    cout << "Bubble Sort Result: ";
    for (int num : x) {
        cout << num << " ";
    }
    cout << endl;

    x = {1, 3, 5, 10, 12};
    target = 3;
    result = binary_search(x, target);
    cout << "Binary Search Result: " << result << endl;

    x = {6, 5, 12, 10, 9, 1};
    x = merge_sort(x);
    cout << "Merge Sort Result: ";
    for (int num : x) {
        cout << num << " ";
    }
    cout << endl;

    x = {1, 2, 5, 4, 7, 7};
    bool hasDuplicate = duplicate(x);
    cout << "Duplicate: " << (hasDuplicate ? "Yes" : "No") << endl;

    return 0;
}
