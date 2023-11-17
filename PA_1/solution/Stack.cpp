#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

#include <stdexcept>
#include <iostream>

using namespace std;

// This is the base class for ArrayStack and DoublingArrayStack. The only 
// difference between ArrayStack and DoublingArrayStack is the growth 
// rate. Since stack growth is handled in push(), we declare push() as pure 
// virtual. For LinkedListStack, it's recommended to use a separete class 
// instead of inheriting from AbstractStack.
// template <class T>
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


#ifndef STACK_ARRAY_L
#define STACK_ARRAY_L

class StackArrayLinear : public AbstractStack{
private:
    int* data;
    int length;
    int topIndex;

public:
    StackArrayLinear(){
        length = 10;
        data = new int[length];
        topIndex = -1;
    }

    ~StackArrayLinear(){
        delete[] data;
    }

    bool isEmpty(){
        return topIndex == -1;
    }

    int size(){
        return topIndex + 1;
    }

    int top(){
        
        if(isEmpty()){
            // throw std::exception();
            std::cout<<"Empty\n";
        }
        return data[topIndex];
    }

    int pop(){
        if(isEmpty()){
            throw std::exception();
        }
        return data[topIndex--];
    }

    void push(int e){
        if(topIndex == length - 1){
            int* temp = new int[length + 10];
            for(int i = 0; i < length; i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            length += 10;
        }
        data[++topIndex] = e;
    }

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
        length = 10;
        data = new int[length];
        topIndex = -1;
    }

    ~StackArrayDouble(){
        delete[] data;
    }

    bool isEmpty(){
        return topIndex == -1;
    }

    int size(){
        return topIndex + 1;
    }

    int top(){
        
        if(isEmpty()){
            // throw std::exception();
            std::cout<<"Empty\n";
        }
        return data[topIndex];
    }

    int pop(){
        if(isEmpty()){
            throw std::exception();
        }
        return data[topIndex--];
    }

    void push(int e){
        if(topIndex == length - 1){
            int* temp = new int[length * 2];
            for(int i = 0; i < length; i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            length *= 2;
        }
        data[++topIndex] = e;
    }

};
#endif

#ifndef STACK_LinkedList_H
#define STACK_LinkedList_H
class Node{
public:
    int data;
    Node* next;
};
class StackLinkedList : public AbstractStack{
private:
    Node* head;
    int length;
public:
    StackLinkedList(){
        head = NULL;
        length = 0;
    }

    ~StackLinkedList(){
        Node* temp = head;
        while(temp != NULL){
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }

    bool isEmpty(){
        return length == 0;
    }

    int size(){
        return length;
    }

    int top(){
        if(isEmpty()){
            std::cout<<"Empty\n";
        }
        return head->data;
    }

    int pop(){
        if(isEmpty()){
            std::cout<<"Empty\n";
        }
        Node* temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        length--;
        return data;
    }

    void push(int e){
        Node* temp = new Node();
        temp->data = e;
        temp->next = head;
        head = temp;
        length++;
    }

};

#endif

#ifndef MAIN
int main(){
    cout<<"Hello World"<<endl;
    return 0;
}
#endif