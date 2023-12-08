#include <stdio.h>
#include <exception>
#include <assert.h>
#include <iostream>
#include "deque.h"

using namespace std;
#ifndef TEST
int main(){
	Deque<int> intQ;
	assert(intQ.size() == 0);
	intQ.insertFirst(1);
	assert(intQ.size() == 1);
    cout<<"test1"<<endl;
	assert(intQ.removeFirst() == 1);

	assert(intQ.size() == 0);
	intQ.insertFirst(1);
	assert(intQ.size() == 1);
	assert(intQ.removeLast() == 1);

    cout<<"test2"<<endl;
	assert(intQ.size() == 0);
	intQ.insertFirst(1);
	intQ.insertFirst(0);
	assert(intQ.size() == 2);
	assert(intQ.removeLast() == 1);
	assert(intQ.removeLast() == 0);
	return 0;
}
#endif
