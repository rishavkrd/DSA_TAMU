#include <iostream>
#include <cmath>

#define ll long long
using namespace std;

int hashFunction1(string s, int arrSize) {
    ll int hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash = (hash + ((int)s[i]));
        hash = hash % arrSize;
    }
    return hash;
}

int hashFunction2(string s, int arrSize) {

}


bool lookup(bool* bitArray, int arrSize, string s) {
   
}

void insert(bool* bitArray, int arrSize, string s) {

}

int main() {
    bool bitArray[100] = {false};
    int arrSize = 100;
    int matchesCount = 0;
    string sArray[33] = {"algorithm", "data_structures", "efficiency", "computing", "programming", "logic", "compiler", "abstraction", "bytecode", "interface", "interfaces", "modular", "cohesion", "multithreaded", "scalable", "debugging", "frameworks", "optimization", "parallelism", "distributed", "intelligent", "conditional", "iteration", "malicious", "security", "encryption", "networking", "error", "assembly", "virtualization", "algorithmic", "opensource", "cplusplus"};
    for (int i = 0; i < 33; i++) {
        if(lookup(bitArray, arrSize, sArray[i])) {
            matchesCount++;
        }
        insert(bitArray, arrSize, sArray[i]);
    }
    cout<< "Number of matches: " << matchesCount << endl;
    return 0;
}
