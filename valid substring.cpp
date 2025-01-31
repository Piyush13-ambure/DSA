//Given a string s consisting only of opening and closing parentheses ( and ), find the length of the longest valid (well-formed) parentheses substring.

//Note: The length of the smallest valid substring () is 2.

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int findMaxLen(string& s) {
        stack<int> st;
        st.push(-1); // Base index for valid length calculation
        int max_len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push index of '('
            } else { // s[i] == ')'
                st.pop(); // Try to match ')'
                if (st.empty()) {
                    st.push(i); // Push as new base if stack is empty
                } else {
                    max_len = max(max_len, i - st.top()); // Compute length
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    string s = "(()))())(";
    cout << sol.findMaxLen(s) << endl; // Output: 4
    return 0;
}
