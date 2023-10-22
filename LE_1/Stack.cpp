#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

#include <stdexcept>
#include <iostream>

using namespace std;

// The AbstractStack class defies the interface for a stack.
// Implement all the virtual methods in this class. 

class AbstractStack {
private:
    // Your data here...

public:
    AbstractStack() {
    }

    ~AbstractStack() {
    }

    virtual bool isEmpty() = 0;
    virtual int size() = 0;

    // * Returns top element.
    // * Throw an exception if the stack is empty.
    virtual int top() = 0;

    // * Removes and returns top element.
    // * Throw an exception if the stack is empty.
    virtual int pop() = 0;

    // * Declared as pure virtual.
    // * Overload this function in your child class!
    virtual void push (int e) = 0;
};

#endif

#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

class Stack : public AbstractStack{
private:
    int* data;
    int length;
    int topIndex;

public:
    Stack(){
    }

    ~Stack(){
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

int main(){
    cout<<"Hello World"<<endl;
}