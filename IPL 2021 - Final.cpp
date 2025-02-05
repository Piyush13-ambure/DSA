//IPL 2021 Finals are here and it is between the most successful team of the IPL Mumbai Indians and the team striving to grab their first trophy Royal Challengers Banglore. Rohit Sharma, captain of the team Mumbai Indians has the most experience in IPL finals, he feels lucky if he solves a programming question before the IPL finals. So, he asked the team's head coach  Mahela Jayawardene for a question. Question is, given a string S consisting only of opening and closing parenthesis 'ie '('  and ')',  the task is to find out the length of the longest valid parentheses substring.

//NOTE: The length of the smallest valid substring ( ) is 2.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLen(string s) {
        stack<int> st;
        st.push(-1);  // Base case to handle edge cases
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);  // Store index of '('
            } else {
                st.pop();  // Try to match with '('
                if (!st.empty()) {
                    maxLength = max(maxLength, i - st.top());
                } else {
                    st.push(i);  // Store last unmatched ')'
                }
            }
        }
        return maxLength;
    }
};

int main() {
    Solution obj;
    cout << obj.findMaxLen("(()(") << endl;     // Output: 2
    cout << obj.findMaxLen("()(())(") << endl;  // Output: 6
    return 0;
}
