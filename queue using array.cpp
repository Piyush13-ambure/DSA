//Implement a Queue using an Array. Queries in the Queue are of the following type:
//(i) 1 x   (a query of this type means  pushing 'x' into the queue)
//(ii) 2     (a query of this type means to pop an element from the queue and print the popped element. If the queue is empty then return -1)

//We just have to implement the functions push and pop and the driver code will handle the output.
//  main.cpp
//  queue using array
//
//  Created by piyush ambure on 15/01/25.
//

#include <iostream>
using namespace std;

// Struct for queue node
struct QueueNode {
    int data;
    QueueNode* next;
};

// Class for queue
class MyQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    MyQueue() : front(nullptr), rear(nullptr) {}

    // Push function to add an element to the queue
    void push(int x);

    // Pop function to remove and return an element from the queue
    int pop();
};

// Function to push an element into the queue
void MyQueue::push(int x) {
    QueueNode* newNode = new QueueNode;  // Create a new node
    newNode->data = x;                    // Set the data of the new node
    newNode->next = nullptr;              // Set the next pointer to nullptr (end of queue)

    if (!rear) {  // If the queue is empty (no rear element)
        front = rear = newNode;  // Both front and rear point to the new node
    } else {
        rear->next = newNode;    // Link the new node after the current rear node
        rear = newNode;          // Move rear to the newly added node
    }
}

// Function to pop an element from the queue
int MyQueue::pop() {
    if (!front) {  // If the queue is empty
        return -1;
    }

    int result = front->data;  // Get the data from the front node
    QueueNode* temp = front;   // Temporarily store the front node
    front = front->next;       // Move the front pointer to the next node

    if (!front) {  // If the queue is now empty
        rear = nullptr;  // Set rear to nullptr
    }

    delete temp;  // Free the memory of the old front node
    return result;
}

// Driver code
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << endl;  // Output: 1
    cout << q.pop() << endl;  // Output: 2
    cout << q.pop() << endl;  // Output: 3
    cout << q.pop() << endl;  // Output: -1 (queue is empty)

    return 0;
}

