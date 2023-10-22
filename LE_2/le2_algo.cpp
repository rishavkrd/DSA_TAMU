#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool PLOT_GRAPH = true;

void plotBarGraph(const vector<double>& data, const vector<int>& n) {
    int maxValue = *max_element(data.begin(), data.end());

    for (int i = 0; i < data.size(); i++) {
        int barLength = static_cast<int>(data[i] * 80 / maxValue); // Scale the bar length
        if(i==data.size()/2){
            cout << "n " << n[i] << "\t |";
        }else{
            cout << "  " << n[i] << "\t |";
        }
        for (int j = 0; j < barLength; j++) {
            cout << "*";
        }
        cout << " (" << data[i] << ")\n";
    }
}

void algo1(vector<int>& lis_arr) {
    int n = lis_arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lis_arr[j] > lis_arr[j + 1]) {
                swap(lis_arr[j], lis_arr[j + 1]);
            }
        }
    }
}

void measureAlgo1(){
    vector<double> algo1_time;
    vector<int> datapoints1 = {1, 101, 201, 301, 401, 501, 601, 701, 801, 901};
    
    cout<<"algo1"<<endl;
    
    for (int i = 0; i < datapoints1.size(); i++) {
        vector<int> x;
        for (int j = 0; j < datapoints1[i]; j++) {
            x.push_back(rand() % 100 + 1);
        }
        auto start = chrono::high_resolution_clock::now();
        algo1(x);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        algo1_time.push_back(duration.count());
    }
    if(PLOT_GRAPH) plotBarGraph( algo1_time, datapoints1);
}

int algo2(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    if (n > 2) {
        return algo2(n - 1) + algo2(n - 2);
    }
    return -1;
}

void measureAlgo2(){
    // Measuring time for algo2
    vector<double> algo2_time;
    vector<int> datapoints2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 20, 25,26,27,28,29,30,31,32,33,34,39,40};
    
    cout<<"algo2"<<endl;
    
    for (int i = 0; i < datapoints2.size(); i++) {
        auto start = chrono::high_resolution_clock::now();
        algo2(datapoints2[i]);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        algo2_time.push_back(duration.count());
    }
    if(PLOT_GRAPH) plotBarGraph( algo2_time, datapoints2);
}


int algo3(const vector<int>& lis_arr, int target, int low = 0, int high = -1) {
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
        return algo3(lis_arr, target, low, midpoint - 1);
    } else {
        return algo3(lis_arr, target, midpoint + 1, high);
    }
}

void measeureAlgo3(){
    // Measuring time for algo3
    vector<double> algo3_time;
    vector<int> datapoints3;

    cout<<"algo3"<<endl;
    
    for (int i = 1; i < 10000; i += 100) {
        datapoints3.push_back(i);
    }

    for (int i = 0; i < datapoints3.size(); i++) {
        vector<int> x;
        for (int j = 0; j < datapoints3[i]; j++) {
            x.push_back(rand() % 100 + 1);
        }
        auto start = chrono::high_resolution_clock::now();
        algo3(x, 456);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        algo3_time.push_back(duration.count());
    }
    if(PLOT_GRAPH) plotBarGraph( algo3_time, datapoints3);
}

int algo4(const vector<int>& lis_arr, int target) {
    for (int i = 0; i < lis_arr.size(); i++) {
        if (lis_arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void measeureAlgo4(){
    // Measuring time for algo4
    vector<double> algo4_time;
    vector<int> datapoints4;
    cout<<"algo4"<<endl;
    // Generating datapoints similar to your Python code
    for (int i = 1; i < 10000; i += 100) {
        datapoints4.push_back(i);
    }

    for (int i = 0; i < datapoints4.size(); i++) {
        vector<int> x;
        for (int j = 0; j < datapoints4[i]; j++) {
            x.push_back(rand() % 100 + 1);
        }
        auto start = chrono::high_resolution_clock::now();
        algo4(x, 785);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        algo4_time.push_back(duration.count());
    }
    if(PLOT_GRAPH) plotBarGraph( algo4_time, datapoints4);
}

vector<int> algo5_helper(const vector<int>& left, const vector<int>& right) {
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
    while (i < left.size()) {
        output.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        output.push_back(right[j]);
        j++;
    }
    return output;
}

vector<int> algo5(vector<int>& lis_arr) {
    int list_length = lis_arr.size();
    if (list_length == 1) {
        return lis_arr;
    } else {
        int mid_point = list_length / 2;
        vector<int> left_partition(lis_arr.begin(), lis_arr.begin() + mid_point);
        vector<int> right_partition(lis_arr.begin() + mid_point, lis_arr.end());
        return algo5_helper(algo5(left_partition), algo5(right_partition));
    }
}

void measureAlgo5(){
    // Measuring time for algo5
    vector<double> algo5_time;
    vector<int> datapoints5;
    cout<<"algo5"<<endl;
    // Generating datapoints similar to your Python code
    for (int i = 1; i < 10000; i += 500) {
        datapoints5.push_back(i);
    }

    for (int i = 0; i < datapoints5.size(); i++) {
        vector<int> x;
        for (int j = 0; j < datapoints5[i]; j++) {
            x.push_back(rand() % 100 + 1);
        }
        auto start = chrono::high_resolution_clock::now();
        algo5(x);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        algo5_time.push_back(duration.count());
    }

    if(PLOT_GRAPH) plotBarGraph( algo5_time, datapoints5);
}


int main() {
    cout<<"To plot graph ser PLOT_GRAPH = true"<<endl;
    measureAlgo1(); 
    measureAlgo2();
    measeureAlgo3();
    measeureAlgo4();
    measureAlgo5();

    return 0;
}
