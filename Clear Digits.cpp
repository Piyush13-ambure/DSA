/*You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk; 

        for (char ch : s) {
            if (isdigit(ch)) {
                // Remove the closest non-digit character to its left
                if (!stk.empty() && isalpha(stk.top())) {
                    stk.pop();
                }
            } else {
                stk.push(ch); // Push non-digit characters
            }
        }
        
        // Reconstruct the resulting string
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        return result;
    }
};

// Driver code
int main() {
    Solution sol;
    cout << sol.clearDigits("abc") << endl;  // Output: "abc"
    cout << sol.clearDigits("cb34") << endl; // Output: ""
    cout << sol.clearDigits("a1b2c3") << endl; // Output: ""
    cout << sol.clearDigits("ab12cd34") << endl; // Output: ""
    return 0;
}
