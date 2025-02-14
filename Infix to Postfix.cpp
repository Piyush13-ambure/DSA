/*Given an infix expression in the form of string s. Convert this infix expression to a postfix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. Ignore the right associativity of ^.*/


#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to return precedence of operators
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0; // For '('
    }

    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        stack<char> st;
        string postfix = "";

        for (char c : s) {
            if (isalnum(c)) { // If operand, add to output
                postfix += c;
            } 
            else if (c == '(') {
                st.push(c);
            } 
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                st.pop(); // Remove '(' from stack
            } 
            else { // Operator encountered
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop remaining operators from stack
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }
};

int main() {
    string s;
    cout << "Enter infix expression: ";
    cin >> s;

    Solution sol;
    cout << "Postfix Expression: " << sol.infixToPostfix(s) << endl;

    return 0;
}
