//Given a valid expression containing only binary operators '+', '-', '*', '/' and operands, remove all the redundant parenthesis.

//A set of parenthesis is said to be redundant if, removing them, does not change the value of the expression.
//Note: The operators '+' and '-' have the same priority. '*' and '/' also have the same priority. '*' and '/' have more priority than '+' and '-'.


#include <bits/stdc++.h>
using namespace std;

class Solution {   
public:
    string removeBrackets(string s) {    
        int n = s.length();
        vector<bool> redundant(n, false);
        stack<int> st;  // Stores indices of '('
        vector<int> pairIndex(n, -1);  // Stores the matching ')' for each '('

        // Map of operator precedence
        unordered_map<char, int> precedence{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

        // Step 1: Identify pairs of parentheses
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int openIdx = st.top();
                st.pop();
                pairIndex[openIdx] = i;
            }
        }

        // Step 2: Identify redundant parentheses
        function<bool(int, int)> isRedundant = [&](int l, int r) {
            int pos = l + 1;  // Skip '('
            int minPrecedence = 3;  // Higher than any operator
            bool hasOperator = false;

            while (pos < r) {
                if (s[pos] == '(') {
                    pos = pairIndex[pos] + 1;
                } else if (precedence.count(s[pos])) {
                    minPrecedence = min(minPrecedence, precedence[s[pos]]);
                    hasOperator = true;
                    pos++;
                } else {
                    pos++;
                }
            }

            // A single operand inside parentheses is redundant
            if (!hasOperator) return true;

            // Check the operator before '(' and after ')'
            char before = (l > 0) ? s[l - 1] : ' ';
            char after = (r < n - 1) ? s[r + 1] : ' ';

            // If the parenthesis does not change precedence rules, it's redundant
            if (precedence.count(before) && precedence[before] >= minPrecedence) return true;
            if (precedence.count(after) && precedence[after] >= minPrecedence) return true;

            return false;
        };

        // Step 3: Mark redundant parentheses
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' && isRedundant(i, pairIndex[i])) {
                redundant[i] = redundant[pairIndex[i]] = true;
            }
        }

        // Step 4: Construct the final string without redundant parentheses
        string result;
        for (int i = 0; i < n; i++) {
            if (!redundant[i]) result += s[i];
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    string expression = "((a+b))";
    cout << sol.removeBrackets(expression) << endl; // Output: "a+b"

    expression = "(a+(b*c))";
    cout << sol.removeBrackets(expression) << endl; // Output: "a+b*c"

    expression = "((a+b)*(c-d))";
    cout << sol.removeBrackets(expression) << endl; // Output: "(a+b)*(c-d)"

    return 0;
}
