#define TEST
#include "main.cpp"

int main(){
    int count = 1000000000;
    while (count--) {
        memoryLeak();
    }
    cout << "Passed: Memory Leak Fixed" << endl;
}