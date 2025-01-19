//Given a number n, find the value of n raised to the power of its own reverse.

//Note: The result will always fit into a 32-bit signed integer.
#include <iostream>
using namespace std;

class Solution {
public:
    // Function to calculate n raised to the power of its own reverse.
    int reverseExponentiation(int n) {
        int reverse = 0, temp = n;

        // Reverse the number
        while (temp > 0) {
            reverse = reverse * 10 + (temp % 10);
            temp /= 10;
        }

        int result = 1;
        int base = n;
        int mod = INT32_MAX; // Result will always fit into a 32-bit signed integer.

        // Compute n^reverse using modular exponentiation
        while (reverse > 0) {
            if (reverse % 2 == 1) {
                result = result * base % mod;
            }
            base = base * base % mod;
            reverse /= 2;
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    Solution sol;
    int result = sol.reverseExponentiation(n);

    cout << "The result of " << n << " raised to the power of its reverse is: " << result << endl;

    return 0;
}
