//Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
//Note: The input strings may contain leading zeros but the output string should not have any leading zeros.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1, j = s2.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int bit1 = (i >= 0) ? s1[i--] - '0' : 0;
            int bit2 = (j >= 0) ? s2[j--] - '0' : 0;
            
            int sum = bit1 + bit2 + carry;
            result.push_back((sum % 2) + '0');  // Append the sum mod 2
            carry = sum / 2;                    // Compute new carry
        }

        reverse(result.begin(), result.end());  // Reverse final string
        return result;
    }
};

// **Main function for testing**
int main() {
    string s1 = "1101", s2 = "111";
    
    Solution sol;
    string output = sol.addBinary(s1, s2);
    
    cout << output << endl;  // Expected Output: "10100"
    
    return 0;
}
