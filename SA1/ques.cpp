#include <iostream>
# include <vector>

using namespace std;
// Question 1:
// --------------------------------------------------------------------------------------------
// Node class for the individual nodes
class Node {
public:
    int data;
    Node* next;

    // Constructor for Node class
    Node(int data) : data(data), next(nullptr) {}
};

// Manager class to link the nodes and manage the overall list
class LinkedList {
public:
    Node* head;

    // Constructor for LinkedList class
    LinkedList() : head(nullptr) {}

    // Push: Adds a new element at the head of the list
    void push(int data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            Node* new_node = new Node(data);
            new_node->next = head;
            head = new_node;
        }
    }

    // Pop: Deletes the element at the last and returns the value of it
    int pop() {
        if (head == nullptr) {
            return -1; // You can return an appropriate value for an empty list
        } else {
            int popped = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            return popped;
        }
    }

    // Returns the size of the linked list
    int size() {
        Node* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to insert a node containing data at some specified position between 1 and x
    void insert(int data, int position) {
        // Implement your code here
    }

    // Function to delete a node at the specified position between 1 and x
    void remove(int position) {
        // Implement your code here
    }

    // Return the element at the top of the linked list without removing it
    int top() {
        if (head == nullptr) {
            return -1; // You can return an appropriate value for an empty list
        } else {
            return head->data;
        }
    }

    // Return true if the linked list is empty, false if not
    bool isEmpty() {
        return head == nullptr;
    }

    void printIsEmpty() {
        if (isEmpty()) {
            std::cout << "\nLinked list is Empty\n";
        } else {
            std::cout << "\nLinked list is not Empty\n";
        }
    }

    // Reverses the linked list in place
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void printList() {
        Node* temp = head;
        std::cout << "\nThe linked list created is as follows: \n";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

// Question 2:
// --------------------------------------------------------------------------------------------
class QueueUsingArrays {
public:
    vector<int> queue;
    int front;
    int rear;

    QueueUsingArrays() : front(0), rear(0) {}

    // Enqueue Function
    void enqueue(int data, int tag) {
        queue.push_back(data);
        rear++;
    }

    // Dequeue Function
    int dequeue() {
        if (isEmpty()) {
            // std::cout << "\nQueue is empty" << std::endl;
            return -1; // You can return an appropriate value for an empty queue
        } else {
            int frontElement = queue[front];
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
                std::cout << queue[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Print front of the queue
    int frontElement() {
        if (isEmpty()) {
            return -1; // You can return an appropriate value for an empty queue
        } else {
            return queue[front];
        }
    }
};


#ifndef TEST
int main() {
    LinkedList myLinkedList;
    myLinkedList.push(1);
    myLinkedList.push(2);
    myLinkedList.push(3);
    myLinkedList.insert(4, 4);
    myLinkedList.printList();  // Output: 3 2 1 4


    QueueUsingArrays myQueue;
    myQueue.enqueue(1, 0);
    myQueue.enqueue(2, 0);
    myQueue.enqueue(3, 0);

    myQueue.printQueue();  // Output: 1 2 3

    int front = myQueue.frontElement();
    std::cout << "Front of the queue: " << front << std::endl; // Output: Front of the queue: 1

    myQueue.dequeue();
    myQueue.printQueue();  // Output: 2 3

    myQueue.printIsEmpty(); // Output: Queue is not Empty

    return 0;
}
#endif