//Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.

//twoStacks : Initialize the data structures and variables to be used to implement  2 stacks in one array.
//push1 : pushes element into the first stack.
//push2 : pushes element into the second stack.
//pop1 : pops an element from the first stack and returns the popped element. If the first stack is empty, it should return -1.
//pop2 : pops an element from the second stack and returns the popped element. If the second stack is empty, it should return -1.
//  main.cpp
//  2 stack
//
//  Created by piyush ambure on 14/01/25.
//
#include <iostream>
#include <vector>
using namespace std;

class twoStacks {
private:
    vector<int> arr; // Shared array
    int top1;        // Top pointer for stack1
    int top2;        // Top pointer for stack2
    int size;        // Maximum size of the array

public:
    // Constructor to initialize data structures
    twoStacks(int n = 100) {
        size = n;
        arr.resize(size);
        top1 = -1;           // Initialize top1 to -1 (empty)
        top2 = size;         // Initialize top2 to size (empty)
    }

    // Function to push an integer into stack1
    void push1(int x) {
        if (top1 + 1 < top2) { // Ensure there is space between top1 and top2
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow in stack1" << endl;
        }
    }

    // Function to push an integer into stack2
    void push2(int x) {
        if (top1 + 1 < top2) { // Ensure there is space between top1 and top2
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overflow in stack2" << endl;
        }
    }

    // Function to pop an element from stack1
    int pop1() {
        if (top1 >= 0) { // Ensure stack1 is not empty
            int popped = arr[top1];
            top1--;
            return popped;
        } else {
            return -1; // Stack1 is empty
        }
    }

    // Function to pop an element from stack2
    int pop2() {
        if (top2 < size) { // Ensure stack2 is not empty
            int popped = arr[top2];
            top2++;
            return popped;
        } else {
            return -1; // Stack2 is empty
        }
    }
};

int main() {
    // Example usage of twoStacks
    twoStacks ts(10); // Initialize with array size 10

    ts.push1(5);
    ts.push1(10);
    ts.push2(15);
    ts.push2(20);

    cout << "Pop from stack1: " << ts.pop1() << endl; // Output: 10
    cout << "Pop from stack2: " << ts.pop2() << endl; // Output: 20

    ts.push1(25);
    cout << "Pop from stack1: " << ts.pop1() << endl; // Output: 25
    cout << "Pop from stack2: " << ts.pop2() << endl; // Output: 15

    return 0;
}
