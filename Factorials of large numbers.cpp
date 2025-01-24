//Given an integer n, find its factorial. Return a list of integers denoting the digits that make up the factorial of n.



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> factorial(int n) {
        vector<int> result; // To store the digits of the factorial
        result.push_back(1); // Initial factorial value is 1 (0! = 1 and 1! = 1)

        for (int i = 2; i <= n; i++) {
            multiply(result, i);
        }

        reverse(result.begin(), result.end()); // Reverse to get digits in correct order
        return result;
    }

private:
    void multiply(vector<int>& result, int x) {
        int carry = 0;

        // Multiply x with each digit of the current result
        for (int i = 0; i < result.size(); i++) {
            int prod = result[i] * x + carry;
            result[i] = prod % 10; // Store the last digit of the product
            carry = prod / 10;    // Carry the remaining digits
        }

        // Add remaining carry digits to the result
        while (carry > 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
};

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    Solution sol;
    vector<int> result = sol.factorial(n);

    cout << "The factorial of " << n << " is: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << "\n";

    return 0;
}
