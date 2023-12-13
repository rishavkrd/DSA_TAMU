#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//Node to store the data (Linked List)
class Node{
public:
	string key;
	int value;
	Node(string key,int value){
		this->key = key;
		this->value = value;
	}
};


//LRU Cache Data Structure
class LRUCache{
public:
	int maxSize;
	list<Node> l;
	unordered_map<string,list<Node>::iterator > m;

	LRUCache(int maxSize){
		this->maxSize = maxSize > 1 ? maxSize : 1;
	}

	void insertKeyValue(string key,int value){
	}

	int* getValue(string key){

	}

	string mostRecentKey(){
	}

};

#ifndef TEST
int main(){
	LRUCache lru(3);
	lru.insertKeyValue("mango",10);
	lru.insertKeyValue("apple",20);
	lru.insertKeyValue("guava",30);
	cout << lru.mostRecentKey() <<endl;

	lru.insertKeyValue("mango",40);
	cout << lru.mostRecentKey() <<endl;

	int *orders = lru.getValue("mango");
	if(orders!=NULL){
		cout<<"Order of Mango "<<*orders <<endl;
	}


	lru.insertKeyValue("banana",20);

	if(lru.getValue("apple")==NULL){
		cout<<"apple doesn't exist";
	}

	if(lru.getValue("guava")==NULL){
		cout<<"guava doesn't exist";
	}

	if(lru.getValue("banana")==NULL){
		cout<<"banana doesn't exist";
	}
	if(lru.getValue("mango")==NULL){
		cout<<"mango doesn't exist";
	}

	return 0;
}	
#endif