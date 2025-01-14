//Given a stack s, delete the middle element of the stack without using any additional data structure.

//Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from the bottom of the stack.
//Note: The output shown by the compiler is the stack from top to bottom.
//  main.cpp
//  delete middele term
//
//  Created by piyush ambure on 14/01/25.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to delete middle element of a stack
    void deleteMid(stack<int>& s) {
        // Helper function to recursively delete the middle element
        int size = s.size();
        int mid = size / 2;  // Middle element index (0-based)
        
        // Recursive function to remove the middle element
        deleteMidRec(s, mid, 0);
    }
    
    // Recursive function to remove the middle element
    void deleteMidRec(stack<int>& s, int mid, int current) {
        if (current == mid) {
            s.pop();  // Remove the middle element
            return;
        }

        // Pop the top element and recurse
        int temp = s.top();
        s.pop();
        
        // Recurse with incremented index
        deleteMidRec(s, mid, current + 1);
        
        // Push the popped element back after recursion
        s.push(temp);
    }
};

int main() {
    Solution sol;
    stack<int> s;
    
    // Push elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    // Call function to delete middle element
    sol.deleteMid(s);
    
    // Output the stack after deleting the middle element
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
