/*You are given an array of strings arr that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

Key Details:

The valid operators are '+', '-', '*', and '/'.
Each operand is guaranteed to be a valid integer or another expression.
The division operation between two integers always rounds the result towards zero, discarding any fractional part.
No division by zero will occur in the input.
The input is a valid arithmetic expression in Reverse Polish Notation.
The result of the expression and all intermediate calculations will fit in a 32-bit signed integer.*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evaluate(vector<string>& arr) {
        stack<int> st;

        for (const string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop two operands
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int result = 0;

                // Apply the operator
                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else if (token == "/") result = a / b; // Integer division rounds towards zero

                st.push(result);
            } else {
                // Convert string to integer and push onto the stack
                st.push(stoi(token));
            }
        }

        return st.top(); // The final result
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    vector<string> arr1 = {"5", "3", "4", "*", "+"};
    cout << "Output: " << sol.evaluate(arr1) << endl;  // Expected: 17

    vector<string> arr2 = {"-8", "3", "/"};
    cout << "Output: " << sol.evaluate(arr2) << endl;  // Expected: -2

    return 0;
}


