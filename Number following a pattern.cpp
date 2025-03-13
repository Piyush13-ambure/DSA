//Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string printMinNumberForPattern(string S) {
        string result = "";
        stack<int> st;
        int num = 1;

        for (char ch : S) {
            st.push(num++);
            if (ch == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }

        // Push the last remaining number
        st.push(num);
        while (!st.empty()) {
            result += to_string(st.top());
            st.pop();
        }

        return result;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    cout << "Output for D: " << sol.printMinNumberForPattern("D") << endl;  // Expected: 21
    cout << "Output for IIDDD: " << sol.printMinNumberForPattern("IIDDD") << endl;  // Expected: 126543
    return 0;
}
