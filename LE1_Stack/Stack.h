#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

#include <stdexcept>

// This is the base class for ArrayStack and DoublingArrayStack. The only 
// difference between ArrayStack and DoublingArrayStack is the growth 
// rate. Since stack growth is handled in push(), we declare push() as pure 
// virtual. For LinkedListStack, it's recommended to use a separete class 
// instead of inheriting from AbstractStack.
template <class T>
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
    virtual T top() throw(std::exception) = 0;

    // * Removes and returns top element.
    // * Throw an exception if the stack is empty.
    virtual T pop() throw(std::exception) = 0;

    // * Declared as pure virtual.
    // * Overload this function in your child class!
    virtual void push (T e) = 0;
};

#endif