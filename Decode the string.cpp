/*Given an encoded string s, the task is to decode it. The encoding rule is :

k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets.
Note: The test cases are generated so that the length of the output string will never exceed 105 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodedString(string &s) {
        stack<string> st;
        stack<int> numStack;
        string currStr = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0'); // Handle multi-digit numbers
            } else if (ch == '[') {
                numStack.push(num); // Store the number of repetitions
                st.push(currStr);   // Store the previous string part
                num = 0;
                currStr = "";
            } else if (ch == ']') {
                string temp = currStr;
                int repeat = numStack.top();
                numStack.pop();

                // Repeat the string 'repeat' times
                currStr = st.top();
                st.pop();
                while (repeat--) {
                    currStr += temp;
                }
            } else {
                currStr += ch; // Build the current string
            }
        }

        return currStr;
    }
};

// Driver Code
int main() {
    Solution obj;
    string s1 = "1[b]";
    cout << obj.decodedString(s1) << endl; // Output: "b"

    string s2 = "3[b2[ca]]";
    cout << obj.decodedString(s2) << endl; // Output: "bcacabcacabcaca"

    return 0;
}
