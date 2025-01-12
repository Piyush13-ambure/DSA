//You are given a string s representing an expression containing various types of brackets: {}, (), and []. Your task is to determine whether the brackets in the expression are balanced. A balanced expression is one where every opening bracket has a corresponding closing bracket in the correct order
//  main.cpp
//
//  Created by piyush ambure on 12/01/25.
//
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isParenthesisBalanced(string& s) {
        stack<char> st;

        // Traverse each character in the string
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // Check for matching closing brackets
            else if (c == ')' || c == '}' || c == ']') {
                // If stack is empty or brackets don't match, return false
                if (st.empty() || !isMatchingPair(st.top(), c)) {
                    return false;
                }
                st.pop(); // Pop the matched opening bracket
            }
        }

        // If stack is empty, all brackets were matched
        return st.empty();
    }

private:
    // Helper function to check if a pair of brackets match
    bool isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};

int main() {
    string s;
    cout << "Enter an expression with brackets: ";
    cin >> s;

    Solution sol;
    if (sol.isParenthesisBalanced(s)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }

    return 0;
}




