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


