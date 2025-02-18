/*You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.*/


#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<int> st;
        int num = 1;

        // Traverse the pattern
        for (int i = 0; i <= pattern.size(); i++) {
            st.push(num++);
            
            // If we reach the end OR we encounter 'I', pop stack elements
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }

        return result;
    }
};

// **Main function to test the code**
int main() {
    Solution sol;
    
    cout << "Output: " << sol.smallestNumber("IIIDIDDD") << endl; // Expected: "123549876"
    cout << "Output: " << sol.smallestNumber("DDD") << endl;      // Expected: "4321"
    cout << "Output: " << sol.smallestNumber("IID") << endl;      // Expected: "12543"
    
    return 0;
}
