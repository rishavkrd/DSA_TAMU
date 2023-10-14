#include <iostream>
#include "Stack.h"

using namespace std;

class StackArrayDouble : public AbstractStack<int>{
private:
    int* data;
    int length;
    int top;

public:
    StackArrayDouble(){
        length = 10;
        data = new int[length];
        top = -1;
    }

    ~StackArrayDouble(){
        delete[] data;
    }

    bool isEmpty(){
        return top == -1;
    }

    int size(){
        return length;
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
        if(top == length - 1){
            int* temp = new int[length * 2];
            for(int i = 0; i < length; i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            length *= 2;
        }
        data[++top] = e;
    }

};
