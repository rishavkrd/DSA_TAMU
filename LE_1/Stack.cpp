#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

#include <stdexcept>
#include <iostream>

using namespace std;

// The AbstractStack class defies the interface for a stack.
// Implement all the virtual methods in your child class that extends the AbstractStack 
// like shown for class StackArrayDouble. 

class AbstractStack {
private:
    // Your data here...

public:
    AbstractStack() {
    }

    ~AbstractStack() {
    }

    // * Overload this function in your child class!
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual int top() = 0;
    virtual int pop() = 0;
    virtual void push (int e) = 0;
};

#endif

#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

class StackArrayDouble : public AbstractStack{
private:
    int* data;
    int length;
    int topIndex;

public:
    StackArrayDouble(){
    }

    bool isEmpty(){
        return false;
    }

    int size(){
        return 0;
    }

    int top(){
        return 0;
    }

    int pop(){
        return 0;
    }

    void push(int e){
    }

};
#endif
class StackArrayLinear : public AbstractStack{};
class StackLinkedList : public AbstractStack{};
#ifndef TEST
int main(){
    cout<<"Hello World"<<endl;
}
#endif