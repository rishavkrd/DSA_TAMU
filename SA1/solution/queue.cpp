#include <iostream>
#include <vector>

using namespace std;

class QueueUsingArrays {
public:
    vector<pair<int, string>> queue;
    int front;
    int rear;

    QueueUsingArrays() : front(0), rear(0) {}

    // Enqueue Function
    void enqueue(int data, string tag) {
        queue.push_back({data,tag});
        rear++;
    }

    // Dequeue Function
    pair<int,string> dequeue() {
        if (isEmpty()) {
            // std::cout << "\nQueue is empty" << std::endl;
            return {-1, ""}; // You can return an appropriate value for an empty queue
        } else {
            pair<int, string> frontElement = queue[front];
            front++;
            return frontElement;
        }
    }

    // Returns the size of the queue
    int size() {
        return rear - front;
    }

    // Function to check if the queue is empty or not
    bool isEmpty() {
        return front == rear;
    }

    void printIsEmpty() {
        if (isEmpty()) {
            std::cout << "Queue is Empty" << std::endl;
        } else {
            std::cout << "Queue is not Empty" << std::endl;
        }
    }

    // Function to print all the queue elements
    void printQueue() {
        if (isEmpty()) {
            std::cout << "\nQueue is Empty" << std::endl;
        } else {
            for (int i = front; i < rear; i++) {
                std::cout << queue[i].first << "(" << queue[i].second << "), ";
            }
            std::cout << std::endl;
        }
    }

    // Print front of the queue
    pair<int,string> frontElement() {
        if (isEmpty()) {
            return {-1, ""}; // You can return an appropriate value for an empty queue
        } else {
            return queue[front];
        }
    }
};

void testQueueInsert123(){
    QueueUsingArrays myQueue;
    myQueue.enqueue(1, "A");
    myQueue.enqueue(2, "B");
    myQueue.enqueue(3, "C");

    myQueue.printQueue();  // Output: 1(A), 2(B), 3(C)
}

void testQueueFront(){
    QueueUsingArrays myQueue;
    myQueue.enqueue(1, "A");
    myQueue.enqueue(2, "B");
    myQueue.enqueue(3, "C");
    auto front = myQueue.frontElement();
    std::cout << "Front of the queue: " << front.first << ", "<< front.second << std::endl; // Output: Front of the queue: 1

}

void testDequeue(){
    QueueUsingArrays myQueue;
    myQueue.enqueue(1, "A");
    myQueue.enqueue(2, "B");
    myQueue.enqueue(3, "C");
    myQueue.dequeue();
    myQueue.printQueue();  // Output: 2(B), 3(C)
}

void testQueueIsEmpty(){
    QueueUsingArrays myQueue;
    myQueue.enqueue(1, "A");
    myQueue.enqueue(2, "B");
    myQueue.enqueue(3, "C");
    myQueue.dequeue();
    myQueue.printIsEmpty(); // Output: Queue is not Empty
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.printIsEmpty(); // Output: Queue is Empty
}


int main() {
    
    testQueueInsert123();
    testQueueFront();
    testDequeue();
    testQueueIsEmpty();
    
    return 0;
}
