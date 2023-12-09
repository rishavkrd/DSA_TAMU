#define TEST

#include <iostream>
#include "./Stack.cpp"

using namespace std;

int testStackPush(AbstractStack *s){
    s->push(1);
    s->push(2);
    s->push(5);
    if(s->size() != 3){
        return 0;
    }
    return 1;
}
int testStackPop(AbstractStack *s){
    s->push(1);
    s->push(2);
    s->push(3);
    if(s->pop() != 3){
        return 0;
    }
    return 1;
}

int testStackTop(AbstractStack *s){
    s->push(1);
    s->push(2);
    s->push(10);
    if(s->top() != 10){
        return 0;
    }
    return 1;
}

int testStackEmpty(AbstractStack *s){
    if(!s->isEmpty()){
        return 0;
    }
    s->push(1);
    if(s->isEmpty()){
        return 0;
    }
    s->pop();
    if(!s->isEmpty()){
        return 0;
    }
    return 1;
}
//test edge case of size doubling

int main(){

    cout<<"Test Stack with Array which Doubles\n";
    int score1 = 0;
    AbstractStack *stackArrayDouble = new StackArrayDouble();
    score1+=testStackEmpty(stackArrayDouble);
    cout<<"Test Stack Empty: "<< score1<<endl;
    score1+=testStackPush(stackArrayDouble);
    cout<<"Test Stack Push: "<<score1<<endl;
    score1+=testStackPop(stackArrayDouble);
    cout<<"Test Stack Pop: "<<score1<<endl;
    score1+=testStackTop(stackArrayDouble);
    cout<<"Test Stack Top: "<<score1<<endl;

    cout<<"Test Stack with Array which Linearly Increases\n";
    AbstractStack *stackArrayLinear = new StackArrayLinear();

    score1+=testStackEmpty(stackArrayLinear);
    cout<<"Test Stack Empty: "<< score1<<endl;
    score1+=testStackPush(stackArrayLinear);
    cout<<"Test Stack Push: "<<score1<<endl;
    score1+=testStackPop(stackArrayLinear);
    cout<<"Test Stack Pop: "<<score1<<endl;
    score1+=testStackTop(stackArrayLinear);
    cout<<"Test Stack Top: "<<score1<<endl;

    cout<<"Test Stack with Linked List\n";
    AbstractStack *stackLinkedList = new StackLinkedList();
    score1+=testStackEmpty(stackLinkedList);
    cout<<"Test Stack Empty: "<< score1<<endl;
    score1+=testStackPush(stackLinkedList);
    cout<<"Test Stack Push: "<<score1<<endl;
    score1+=testStackPop(stackLinkedList);
    cout<<"Test Stack Pop: "<<score1<<endl;
    score1+=testStackTop(stackLinkedList);
    cout<<"Test Stack Top: "<<score1<<endl;

    cout << "Total Score: " << score1 <<"/12"<< endl;
    return 0;
}