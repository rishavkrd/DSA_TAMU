#include "../solution/Stack.h"
#include <iostream>

using namespace std;

int testStackPush(AbstractStack *s){
    s->push(1);
    s->push(2);
    s->push(5);
    if(s->size() != 3){
        return 0;
    }
    return 10;
}
int testStackPop(AbstractStack *s){
    s->push(1);
    s->push(2);
    s->push(3);
    if(s->pop() != 3){
        return 1;
    }
    return 10;
}

int testStackTop(AbstractStack *s){
    s->push(1);
    s->push(2);
    s->push(10);
    if(s->top() != 10){
        return 0;
    }
    return 10;
}

int testStackEmpty(AbstractStack *s){
    int score = 0;
    if(s->isEmpty()){
        score += 2;
    }
    s->push(1);
    if(!s->isEmpty()){
        score += 3;
    }
    s->pop();
    if(s->isEmpty()){
        score += 5;
    }
    return score;
}

int main(){
    cout<<"Test Stack with Array which Doubles\n";
    AbstractStack *stackArrayDouble = new StackArrayDouble();
    cout<<"Test Stack Empty: "<<testStackEmpty(stackArrayDouble)<<endl;
    cout<<"Test Stack Push: "<<testStackPush(stackArrayDouble)<<endl;
    cout<<"Test Stack Pop: "<<testStackPop(stackArrayDouble)<<endl;
    cout<<"Test Stack Top: "<<testStackTop(stackArrayDouble)<<endl;

    cout<<"Test Stack with Linked List\n";
    AbstractStack *stackLinkedList = new StackLinkedList();
    cout<<"Test Stack Empty: "<<testStackEmpty(stackLinkedList)<<endl;
    cout<<"Test Stack Push: "<<testStackPush(stackLinkedList)<<endl;
    cout<<"Test Stack Pop: "<<testStackPop(stackLinkedList)<<endl;
    cout<<"Test Stack Top: "<<testStackTop(stackLinkedList)<<endl;
    return 0;
}