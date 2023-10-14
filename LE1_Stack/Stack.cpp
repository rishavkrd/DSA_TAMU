#include <iostream>
#include "Stack.h"

using namespace std;

class Stack : public AbstractStack<int>{
private:
    int* data;
    int size;
    int top;

public:
    Stack(){
        size = 10;
        data = new int[size];
        top = -1;
    }

    ~Stack(){
        delete[] data;
    }

    bool isEmpty(){
        return top == -1;
    }

    int size(){
        return size;
    }

    int top(){
        if(isEmpty()){
            throw std::exception();
        }
        return data[top];
    }

    int pop(){
        if(isEmpty()){
            throw std::exception();
        }
        return data[top--];
    }

    void push(int e){
        if(top == size - 1){
            int* temp = new int[size * 2];
            for(int i = 0; i < size; i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            size *= 2;
        }
        data[++top] = e;
    }

};
