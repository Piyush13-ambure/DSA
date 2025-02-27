/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case: INT_MIN / -1 causes overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Get sign of quotient
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // Convert to absolute values (use long to avoid overflow)
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long quotient = 0;

        // Perform bitwise division
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor, multiple = 1;

            // Increase divisor exponentially using bitwise left shift
            while ((tempDivisor << 1) <= absDividend) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the maximum found divisor from dividend
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        // Apply sign and return
        return sign * quotient;
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.divide(10, 3) << endl;  // Output: 3
    cout << sol.divide(7, -3) << endl;  // Output: -2
    cout << sol.divide(-2147483648, -1) << endl;  // Output: 2147483647 (INT_MAX)
    return 0;
}
