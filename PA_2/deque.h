#include "node.h"
using namespace std;
template <class Type>

class Deque {
private:
    int s;
	Node<Type>* firstNode;
	Node<Type>* lastNode;

public:
	Deque() {
	}

	~Deque() {
        delete firstNode;
		delete lastNode;
	}
	
	bool isEmpty() {
	}

	int size() {
	}

	Type first() {

	}

	Type last() {

	}

	void insertFirst(Type o) {

	}

	void insertLast(Type o) {

	}
	
	Type removeFirst() {

	}

	Type removeLast() {

	}
};

#ifndef TEST
int main(){
	return 0;
}
#endif