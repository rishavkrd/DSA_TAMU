#include <iostream>
using namespace std;
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
    // Function to insert a node containing data at a specified position between 1 and x
void insert(int data, int position) {
    if (position <= 0) {
        std::cout << "Invalid position. Position should be a positive integer." << std::endl;
        return;
    }

    Node* new_node = new Node(data);

    if (position == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        Node* current = head;
        int current_position = 1;

        while (current_position < position - 1 && current != nullptr) {
            current = current->next;
            current_position++;
        }

        if (current == nullptr) {
            std::cout << "Position exceeds the size of the linked list." << std::endl;
            delete new_node;
            return;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to delete a node at the specified position between 1 and x
void remove(int position) {
    if (position <= 0) {
        std::cout << "Invalid position. Position should be a positive integer." << std::endl;
        return;
    }

    if (head == nullptr) {
        std::cout << "Linked list is empty. Cannot delete from an empty list." << std::endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        int current_position = 1;

        while (current_position < position - 1 && current != nullptr) {
            current = current->next;
            current_position++;
        }

        if (current == nullptr || current->next == nullptr) {
            std::cout << "Position exceeds the size of the linked list." << std::endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
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
        cout<<"\n";
    }
};


