//
//  main.cpp
//  get min from stack
//
//  Created by piyush ambure on 12/01/25.
//
#include <iostream>
#include <stack>
using namespace std;

class Solution {
    int minEle;
    stack<int> s;

public:
    /* Returns minimum element from stack */
    int getMin() {
        if (s.empty()) {
            return -1; // Stack is empty
        }
        return minEle;
    }

    /* Returns popped element from stack */
    int pop() {
        if (s.empty()) {
            return -1; // Stack is empty
        }

        int topElement = s.top();
        s.pop();

        // If the top element is less than the current minimum,
        // it means we used an encoded value to store the minimum
        if (topElement < minEle) {
            int originalMin = minEle;
            minEle = 2 * minEle - topElement; // Restore the previous minimum
            return originalMin;
        }

        return topElement;
    }

    /* Push element x into the stack */
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minEle = x; // Set the first element as minimum
        } else {
            // Encode the value if x is smaller than the current minimum
            if (x < minEle) {
                s.push(2 * x - minEle);
                minEle = x; // Update minimum
            } else {
                s.push(x); // Normal push
            }
        }
    }
};

int main() {
    Solution sol;
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            sol.push(x);
        } else if (type == 2) {
            cout << "Popped: " << sol.pop() << endl;
        } else if (type == 3) {
            cout << "Minimum: " << sol.getMin() << endl;
        }
    }

    return 0;
}
