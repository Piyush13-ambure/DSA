/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/


#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;  // Use long long to handle INT_MIN
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) { // If exponent is odd
                result *= x;
            }
            x *= x;  // Square the base
            exp /= 2;  // Reduce exponent by half
        }
        return result;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    
    cout << sol.myPow(2.00000, 10) << endl;  // Output: 1024.00000
    cout << sol.myPow(2.10000, 3) << endl;   // Output: 9.26100
    cout << sol.myPow(2.00000, -2) << endl;  // Output: 0.25000

    return 0;
}
