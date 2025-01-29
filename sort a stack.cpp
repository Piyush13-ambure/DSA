//Given a stack, the task is to sort it such that the top of the stack has the greatest element.

#include <iostream>
#include <stack>

using namespace std;

class SortedStack {
public:
    stack<int> s;
    
    void sort();  // Function to sort stack

private:
    void sortedInsert(int x);  // Helper function to insert elements in sorted order
};

// Function to sort the stack using recursion
void SortedStack::sort() {
    if (s.empty()) return;  // Base case

    int topElement = s.top();  // Remove the top element
    s.pop();

    sort();  // Recursively sort the remaining stack

    sortedInsert(topElement);  // Insert the element back in sorted order
}

// Helper function to insert elements in sorted order
void SortedStack::sortedInsert(int x) {
    if (s.empty() || s.top() <= x) {  
        s.push(x);  // Push if stack is empty or top element is smaller
        return;
    }

    int topElement = s.top();  // Remove top element
    s.pop();

    sortedInsert(x);  // Recursively find correct position

    s.push(topElement);  // Push the removed element back
}

// Utility function to print the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Main function to test sorting
int main() {
    SortedStack ss;
    ss.s.push(30);
    ss.s.push(10);
    ss.s.push(50);
    ss.s.push(20);
    ss.s.push(40);

    cout << "Original stack: ";
    printStack(ss.s);

    ss.sort();

    cout << "Sorted stack (greatest at top): ";
    printStack(ss.s);

    return 0;
}
