//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer. The algorithm for myAtoi(string s) is as follows:

//Whitespace: Ignore any leading whitespace (" ").
//signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
//Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
//Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
//Return the integer as the final result.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        long long result = 0;
        int sign = 1;
        
        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Handle optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Convert the digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            i++;
            
            // Step 4: Handle overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }
        
        // Step 5: Return the result with the correct sign
        return result * sign;
    }
};

// Driver function
int main() {
    Solution sol;
    cout << sol.myAtoi("42") << endl;            // Output: 42
    cout << sol.myAtoi(" -042") << endl;         // Output: -42
    cout << sol.myAtoi("1337c0d3") << endl;      // Output: 1337
    cout << sol.myAtoi("0-1") << endl;           // Output: 0
    cout << sol.myAtoi("words and 987") << endl; // Output: 0
    
    return 0;
}
