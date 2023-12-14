#define TEST
#include "lru.cpp"
#include <iostream>
#include <cassert>

int runLRUCacheTests() {
    int score = 0;

    // Test Case 1: Basic Insertion and Retrieval
    LRUCache cache1(3);
    cache1.insertKeyValue("mango", 10);
    cache1.insertKeyValue("apple", 20);
    cache1.insertKeyValue("guava", 30);
    if (cache1.mostRecentKey() == "guava") {
        score++;
        std::cout << "Test Case 1 passed: Most recent key is guava\n";
    } else {
        std::cout << "Test Case 1 failed: Most recent key is not guava\n";
    }

    // Test Case 2: Update Existing Key
    cache1.insertKeyValue("mango", 40);
    if (cache1.mostRecentKey() == "mango") {
        score++;
        std::cout << "Test Case 2 passed: Most recent key is mango\n";
    } else {
        std::cout << "Test Case 2 failed: Most recent key is not mango\n";
    }

    // Test Case 3: Retrieve Value
    int* mangoValue = cache1.getValue("mango");
    if (mangoValue != NULL && *mangoValue == 40) {
        score++;
        std::cout << "Test Case 3 passed: Correct value for mango\n";
    } else {
        std::cout << "Test Case 3 failed: Incorrect value for mango\n";
    }

    // Test Case 4: Insert Additional Items (Cache Full)
    cache1.insertKeyValue("banana", 20);
    if (cache1.getValue("apple") == NULL && cache1.mostRecentKey() == "banana") {
        score++;
        std::cout << "Test Case 4 passed: Correct cache state after insertion\n";
    } else {
        std::cout << "Test Case 4 failed: Incorrect cache state after insertion\n";
    }

    // Test Case 5: Non-Existent Keys
    if (cache1.getValue("grape") == NULL) {
        score++;
        std::cout << "Test Case 5 passed: Correct handling of non-existent key\n";
    } else {
        std::cout << "Test Case 5 failed: Incorrect handling of non-existent key\n";
    }

    // Test Case 6: Empty Cache
    LRUCache emptyCache(1);
    if (emptyCache.mostRecentKey() == "") {
        score++;
        std::cout << "Test Case 6 passed: Most recent key is empty\n";
    } else {
        std::cout << "Test Case 6 failed: Most recent key is not empty\n";
    }

    // Test Case 7: Cache Size Limit
    LRUCache smallCache(1);
    smallCache.insertKeyValue("one", 1);
    smallCache.insertKeyValue("two", 2);  // Evicts "one"
    if (smallCache.getValue("one") == NULL) {
        score++;
        std::cout << "Test Case 7 passed: Correct eviction in small cache\n";
    } else {
        std::cout << "Test Case 7 failed: Incorrect eviction in small cache\n";
    }

    return score;
}

int main() {
    int totalScore = runLRUCacheTests();
    std::cout << "Total Score: " << totalScore << "/7\n";
    return 0;
}