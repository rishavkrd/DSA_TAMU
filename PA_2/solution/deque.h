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
        s=0;
		firstNode = nullptr;
		lastNode = nullptr;
	}

	~Deque() {
        delete firstNode;
		delete lastNode;
	}
	
	bool isEmpty() {
        return s==0;
	}

	int size() {
        return s;
	}

	Type first() {
        return firstNode->getData();
	}

	Type last() {
        return lastNode->getData();
	}

	void insertFirst(Type o) {
        Node<Type>* newNode = new Node<Type>(o);
		if(isEmpty()){
			firstNode = newNode;
			lastNode = newNode;
		}
		else{
			newNode->setNext(firstNode);
			firstNode->setPrev(newNode);
			firstNode = newNode;
		}
		s++;
	}

	void insertLast(Type o) {
        Node<Type>* newNode = new Node<Type>(o);
		if(isEmpty()){
			firstNode = newNode;
			lastNode = newNode;
		}
		else{
			newNode->setPrev(lastNode);
			lastNode->setNext(newNode);
			lastNode = newNode;
		}
		s++;
	}
	
	Type removeFirst() {
        if(isEmpty()){
			cout<<"Deque is empty"<<endl;
			return Type();
		} else{
			Node<Type>* temp = firstNode;
			firstNode = firstNode->getNext();
			if(firstNode!=NULL) firstNode->setPrev(nullptr);
			s--;
			return temp->getData();
		}
	}

	Type removeLast() {
        if(isEmpty()){
			cout<<"Deque is empty"<<endl;
			return Type();
		} else{
			Node<Type>* temp = lastNode;
			lastNode = lastNode->getPrev();
			if(lastNode!=NULL) lastNode->setNext(nullptr);
			s--;
			return temp->getData();
		}
	}
};