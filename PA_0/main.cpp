#include <iostream>
using namespace std;

//Question
// The below code has memory leak, identify where it is and modify the code to fix the memory leak.
 
class MyPointer {
private:
    int* ptr;
public:
    MyPointer(int* p = NULL) { 
        ptr = p; 
    }
};
 
void foo()
{
    MyPointer p(new int(10000));
    return;
}
 
int main()
{   
    int count = 100;
    while (count--) {
        foo();
    }
}