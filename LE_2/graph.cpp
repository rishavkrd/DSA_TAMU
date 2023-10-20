#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;



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

#endif

// int main() {
//     // Sample data (replace with your own data)
//     vector<int> inputData = {5, 10, 105, 200, 1000};
//     vector<int> nums =         {1, 2, 3, 4, 5};

//     // Plot the bar graph
//     plotBarGraph(inputData, nums);

//     return 0;
// }
