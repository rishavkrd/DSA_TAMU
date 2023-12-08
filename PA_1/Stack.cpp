#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

#include <stdexcept>
#include <iostream>

using namespace std;

// The AbstractStack class defies the interface for a stack.
// Create a class which extends AbstractStack like shown for class 'StackArrayDouble'.
// Implement all the virtual methods in your class 'Stack' (not in AbstractStack). 

class AbstractStack {
private:
    // Your data here...

public:
    AbstractStack() {
    }
    // * Overload these function in your child class not here!
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

    ~StackArrayDouble(){
        delete[] data;
    }

    bool isEmpty(){
    }

    int size(){

    }

    int top(){
        
    }

    int pop(){

    }

    void push(int e){

    }

};
#endif

class StackArrayLinear : public AbstractStack{};
class StackLinkedList : public AbstractStack{};

int testStackPush(AbstractStack *s){
    s->push(1);
    s->push(2);
    s->push(5);
    if(s->size() != 3){
        return 0;
    }
    return 10;
}
#ifndef TEST
int main(){
    cout<<"Hello World"<<endl;
    testStackPush(new StackArrayDouble());
    return 0;
}
#endif