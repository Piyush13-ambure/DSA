//Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index for calculating length
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // Store index of '('
            } else { // s[i] == ')'
                st.pop(); // Try to match a '('
                
                if (st.empty()) {
                    st.push(i); // Reset base index
                } else {
                    maxLen = max(maxLen, i - st.top()); // Update max length
                }
            }
        }
        
        return maxLen;
    }
};
