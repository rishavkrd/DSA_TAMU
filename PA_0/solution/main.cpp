// C++ program to demonstrate working of a Pointers
#include <iostream>
using namespace std;
 
class MyPointer {
private:
    int* ptr;
public:
    explicit MyPointer(int* p = NULL) { 
        ptr = p; 
    }
 
    // Destructor
    ~MyPointer() { delete (ptr); }
 
};
 
void memoryLeak()
{
    // Allocate memory to pointer p
    MyPointer p(new int(10000));
    return;
}

#ifndef TEST
int main()
{   
    int count = 100;
    while (count--) {
        memoryLeak();
    }
}
#endif