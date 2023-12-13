#define TEST
#include <iostream>
#include "bloomFilter.cpp"

// Function to run tests for Bloom filter and return the score
int runBloomFilterTests() {
    const int arrSize = 100;
    bool bitArray[arrSize] = {false};
    int score = 0;

    // Test Case 1: Insert and Lookup
    insert(bitArray, arrSize, "apple");
    if (lookup(bitArray, arrSize, "apple") == true && lookup(bitArray, arrSize, "orange") == false) {
        score++;
    } else {
        std::cout << "Test Case 1 failed: Incorrect lookup\n";
    }

    // Test Case 2: Insert Duplicate
    insert(bitArray, arrSize, "apple");
    if (lookup(bitArray, arrSize, "apple") == true) {
        score++;
    } else {
        std::cout << "Test Case 2 failed: Incorrect lookup\n";
    }

    // Test Case 3: Insert Multiple Items
    insert(bitArray, arrSize, "banana");
    insert(bitArray, arrSize, "cherry");
    insert(bitArray, arrSize, "date");
    if (lookup(bitArray, arrSize, "banana") == true && lookup(bitArray, arrSize, "cherry") == true && lookup(bitArray, arrSize, "date") == true) {
        score++;
    } else {
        std::cout << "Test Case 3 failed: Incorrect lookup\n";
    }

    // Test Case 4: Check Non-Existent Items
    if (lookup(bitArray, arrSize, "grape") == false && lookup(bitArray, arrSize, "kiwi") == false) {
        score++;
    } else {
        std::cout << "Test Case 4 failed: Incorrect lookup\n";
    }

    int matchesCount = 0;
    string sArray[33] = {"algorithm", "data_structures", "efficiency", "computing", "programming", "logic", "compiler", "abstraction", "bytecode", "interface", "interfaces", "modular", "cohesion", "multithreaded", "scalable", "debugging", "frameworks", "optimization", "parallelism", "distributed", "intelligent", "conditional", "iteration", "malicious", "security", "encryption", "networking", "error", "assembly", "virtualization", "algorithmic", "opensource", "cplusplus"};
    for (int i = 0; i < 33; i++) {
        if(lookup(bitArray, arrSize, sArray[i])) {
            matchesCount++;
        }
        insert(bitArray, arrSize, sArray[i]);
    }
    std:cout<< "Number of matches <10? : " << matchesCount << endl;
    if (matchesCount < 10) {
        score++;
    } else{
        std::cout << "Test Case 5 failed: Number of matches >10\n";
    }

    return score;
}

int main() {
    int totalScore = runBloomFilterTests();
    std::cout << "Total Score: " << totalScore << "/5\n";
    return 0;
}
