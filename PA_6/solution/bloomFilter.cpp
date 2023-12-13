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
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++) {
        hash = hash + pow(19, i) * s[i];
        hash = hash % arrSize;
    }
    return hash % arrSize;
}

int hashFunction3(string s, int arrSize) {
    ll int hash = 7;
    for (int i = 0; i < s.size(); i++) {
        hash = (hash * 31 + s[i]) % arrSize;
    }
    return hash % arrSize;
}

int hashFunction4(string s, int arrSize) {
    ll int hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++) {
        hash += hash * 7 + s[0] * pow(p, i);
        hash = hash % arrSize;
    }
    return hash;
}

bool lookup(bool* bitArray, int arrSize, string s) {
    int a = hashFunction1(s, arrSize);
    int b = hashFunction2(s, arrSize);
    int c = hashFunction3(s, arrSize);
    int d = hashFunction4(s, arrSize);

    if (bitArray[a] && bitArray[b] && bitArray && bitArray[d]) {
        return true;
    } else {
        return false;
    }
}

void insert(bool* bitArray, int arrSize, string s) {
    if (lookup(bitArray, arrSize, s))
        cout << s << " may already be present" << endl;
    else {
        int a = hashFunction1(s, arrSize);
        int b = hashFunction2(s, arrSize);
        int c = hashFunction3(s, arrSize);
        int d = hashFunction4(s, arrSize);

        bitArray[a] = true;
        bitArray[b] = true;
        bitArray[c] = true;
        bitArray[d] = true;

        cout << s << " inserted" << endl;
    }
    // print bit array
    for (int i = 0; i < arrSize; i++) {
        cout << bitArray[i];
    }
    cout << endl;
}
#ifndef TEST
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
    if(matchesCount < 5){
        cout<< "Passed: Number of matches is less than 5" << endl;
    }
    else{
        cout<< "Failed: Number of matches is greater than or equal to 5" << endl;
    }
    return 0;
}
#endif