//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reverseNum = 0;

        while (x != 0) {
            int digit = x % 10;  // Extract last digit
            
            // Overflow Check: Before multiplying by 10, check if it exceeds 32-bit limit
            if (reverseNum > INT_MAX / 10 || (reverseNum == INT_MAX / 10 && digit > 7)) return 0;
            if (reverseNum < INT_MIN / 10 || (reverseNum == INT_MIN / 10 && digit < -8)) return 0;
            
            reverseNum = reverseNum * 10 + digit;
            x /= 10;  // Remove last digit
        }

        return reverseNum;
    }
};

// Driver function
int main() {
    Solution sol;
    cout << sol.reverse(123) << endl;   // Output: 321
    cout << sol.reverse(-123) << endl;  // Output: -321
    cout << sol.reverse(120) << endl;   // Output: 21
    cout << sol.reverse(1534236469) << endl;  // Output: 0 (overflow case)
    return 0;
}
