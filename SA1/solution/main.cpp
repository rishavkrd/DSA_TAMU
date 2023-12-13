#define TEST
#include "linkedlist.cpp"
#include "queue.cpp"

int testInsertSuccessfull(){
    LinkedList myLinkedList;
    myLinkedList.push(1);
    myLinkedList.push(2);
    myLinkedList.push(3);
    myLinkedList.insert(4, 4);
    myLinkedList.printList();  // Output: 3 2 1 4

    int output[] = {3, 2, 1, 4};
    for(int i = 0; i < 4; i++){
        if(myLinkedList.head != nullptr && myLinkedList.head->data != output[i]){
            std::cout << "Test Insert Successfull: Failed" << std::endl;
            return 0;
        }
        myLinkedList.head = myLinkedList.head->next;
    }
    return 1;
}

int testInsertUnsuccessfull(){
    LinkedList myLinkedList;
    myLinkedList.push(1);
    myLinkedList.push(2);
    myLinkedList.push(3);
    myLinkedList.insert(4, 5); // Error message: Position exceeds the size of the linked list.
    myLinkedList.printList();  // Output: 3 2 1
    if(myLinkedList.size() != 3){
        std::cout << "Test Insert Unsuccessfull: Failed" << std::endl;
        return 0;
    }
    int output[] = {3, 2, 1};
    for(int i = 0; i < 3; i++){
        if(myLinkedList.head != nullptr && myLinkedList.head->data != output[i]){
            std::cout << "Test Insert Successfull: Failed" << std::endl;
            return 0;
        }
        myLinkedList.head = myLinkedList.head->next;
    }
    return 1;

}

int testQueueInsert123(){
    QueueUsingArrays myQueue;
    myQueue.enqueue(1, "A");
    myQueue.enqueue(2, "B");
    myQueue.enqueue(3, "C");
    if(myQueue.size() != 3){
        std::cout << "Test Queue Insert 123: Failed" << std::endl;
        return 0;
    }
    myQueue.printQueue();  // Output: 1(A), 2(B), 3(C)
    return 1;
}

int testQueueFront(){
    QueueUsingArrays myQueue;
    myQueue.enqueue(1, "A");
    myQueue.enqueue(2, "B");
    myQueue.enqueue(3, "C");
    auto front = myQueue.frontElement();
    if(front.first != 1) {
        return 0;
    }
    std::cout << "Front of the queue: " << front.first << ", "<< front.second << std::endl; // Output: Front of the queue: 1
    return 1;
}

int testDequeue(){
    QueueUsingArrays myQueue;
    myQueue.enqueue(1, "A");
    myQueue.enqueue(2, "B");
    myQueue.enqueue(3, "C");
    myQueue.dequeue();
    myQueue.printQueue();  // Output: 2(B), 3(C)
    if(myQueue.size() != 2){
        std::cout << "Test Dequeue: Failed" << std::endl;
        return 0;
    }
    return 1;
}

int testQueueIsEmpty(){
    QueueUsingArrays myQueue;
    myQueue.enqueue(1, "A");
    myQueue.enqueue(2, "B");
    myQueue.enqueue(3, "C");
    myQueue.dequeue();
    myQueue.printIsEmpty(); // Output: Queue is not Empty
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.printIsEmpty(); // Output: Queue is Empty
    if(myQueue.size() != 0){
        std::cout << "Test Queue Is Empty: Failed" << std::endl;
        return 0;
    }
    return 1;
}


int main() {
    cout<<"Linkedlist Tests"<<endl;
    int score = 0;
    score+= testInsertSuccessfull();
    score+= testInsertUnsuccessfull();
    cout<<"Linked list Score: "<<score<<"/2"<<endl;

    cout<<"Queue Tests"<<endl;
    int score2 =0;
    score2+= testQueueInsert123();
    score2+= testQueueFront();
    score2+= testDequeue();
    score2+= testQueueIsEmpty();
    cout<<"Queue Score: "<<score2<<"/4"<<endl;
    cout<<"Total Score: "<<score+score2<<"/6"<<endl;
    return 0;
}