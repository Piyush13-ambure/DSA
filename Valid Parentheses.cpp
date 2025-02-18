
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

*/


#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketMap = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            // If it's a closing bracket
            if (bracketMap.count(c)) {
                if (st.empty() || st.top() != bracketMap[c]) {
                    return false;
                }
                st.pop();
            }
            // If it's an opening bracket, push it onto the stack
            else {
                st.push(c);
            }
        }

        // If stack is empty, all brackets are matched correctly
        return st.empty();
    }
};

// **Main function to test the code**
int main() {
    Solution sol;

    cout << boolalpha; // Print "true" or "false" instead of 1 or 0
    cout << "Output: " << sol.isValid("()") << endl;        // true
    cout << "Output: " << sol.isValid("()[]{}") << endl;    // true
    cout << "Output: " << sol.isValid("(]") << endl;        // false
    cout << "Output: " << sol.isValid("([])") << endl;      // true
    cout << "Output: " << sol.isValid("{[()]}") << endl;    // true
    cout << "Output: " << sol.isValid("{[(])}") << endl;    // false

    return 0;
}
