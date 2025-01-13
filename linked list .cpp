//Let's give it a try! You have a linked list and must implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack.
//The push() method takes one argument, an integer 'x' to be pushed into the stack and pop() which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.
//Note: The input is given in the form of queries. Since there are two operations push() and pop(), there is two types of queries as described below:
//(i) 1   (a query of this type takes x as another parameter and pushes it into the stack)
//(ii) 2  (a query of this type means to pop an element from the stack and return the popped element)
//Input is separated by space and as described above.
//  stack using linked list
//
//  Created by piyush ambure on 13/01/25.
//
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Stack class implemented using a linked list
class myStack {
private:
    Node* head;  // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    myStack() {
        head = nullptr;
    }

    // Push an element onto the stack
    void push(int x) {
        Node* newNode = new Node(x);  // Create a new node
        newNode->next = head;        // Point the new node to the current head
        head = newNode;              // Update the head to the new node
    }

    // Pop the top element from the stack
    int pop() {
        if (head == nullptr) {       // Check if the stack is empty
            return -1;
        }
        int topData = head->data;    // Retrieve the data from the head
        Node* temp = head;           // Temporary pointer to the head node
        head = head->next;           // Move the head to the next node
        delete temp;                 // Free the memory of the old head
        return topData;
    }
};

int main() {
    myStack stack;  // Create a stack object
    int choice;     // User's menu choice
    bool running = true;

    cout << "Welcome to the Stack program!" << endl;

    while (running) {
        cout << "\nMenu:\n";
        cout << "1. Push an element onto the stack\n";
        cout << "2. Pop an element from the stack\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                cout << value << " pushed onto the stack.\n";
                break;
            }
            case 2: {
                int poppedValue = stack.pop();
                if (poppedValue == -1) {
                    cout << "The stack is empty. Nothing to pop.\n";
                } else {
                    cout << "Popped value: " << poppedValue << endl;
                }
                break;
            }
            case 3:
                running = false;
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}


