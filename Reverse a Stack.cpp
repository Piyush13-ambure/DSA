//You are given a stack St. You have to reverse the stack using recursion.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to insert an element at the bottom of the stack
    void insertAtBottom(stack<int> &St, int val) {
        if (St.empty()) {
            St.push(val);
            return;
        }
        
        int top = St.top();
        St.pop();
        insertAtBottom(St, val);
        St.push(top);
    }
    
    // Function to reverse the stack using recursion
    void Reverse(stack<int> &St) {
        if (St.empty()) return;
        
        int top = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, top);
    }
};

// Function to print stack (for testing)
void printStack(stack<int> St) {
    vector<int> temp;
    while (!St.empty()) {
        temp.push_back(St.top());
        St.pop();
    }
    reverse(temp.begin(), temp.end());
    cout << "{";
    for (size_t i = 0; i < temp.size(); i++) {
        cout << temp[i];
        if (i < temp.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

// Main function for testing
int main() {
    Solution obj;
    
    stack<int> St1;
    for (int val : {3, 2, 1, 7, 6}) St1.push(val);
    
    obj.Reverse(St1);
    printStack(St1); // Output: {6, 7, 1, 2, 3}

    stack<int> St2;
    for (int val : {4, 3, 9, 6}) St2.push(val);
    
    obj.Reverse(St2);
    printStack(St2); // Output: {6, 9, 3, 4}

    return 0;
}
