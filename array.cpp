//
//  main.cpp
//  stack using array
//
//  Created by piyush ambure on 13/01/25.
//

#include <iostream>
using namespace std;

#define MAX 1000 // Maximum size of the stack

class MyStack {
    int top;
    int arr[MAX]; // Array to store stack elements

public:
    MyStack() { top = -1; } // Constructor to initialize stack

    // Function to push an element onto the stack
    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    // Function to remove an item from the top of the stack
    int pop() {
        if (top < 0) {
            return -1; // Stack is empty
        }
        return arr[top--];
    }
};

int main() {
    MyStack stack;
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // Push operation
            int x;
            cin >> x;
            stack.push(x);
        } else if (type == 2) { // Pop operation
            cout << stack.pop() << endl;
        }
    }

    return 0;
}
