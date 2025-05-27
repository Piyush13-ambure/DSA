/*You are given positive integers n and m.

Define two integers as follows:

num1: The sum of all integers in the range [1, n] (both inclusive) that are not divisible by m.
num2: The sum of all integers in the range [1, n] (both inclusive) that are divisible by m.
Return the integer num1 - num2.*/

#include <iostream>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n * (n + 1) / 2;
        int count = n / m;
        int sumDivisible = m * count * (count + 1) / 2;

        int num1 = totalSum - sumDivisible;
        int num2 = sumDivisible;

        return num1 - num2;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    cout << "Example 1: " << sol.differenceOfSums(10, 3) << endl; // Output: 19
    cout << "Example 2: " << sol.differenceOfSums(5, 6) << endl;  // Output: 15
    cout << "Example 3: " << sol.differenceOfSums(5, 1) << endl;  // Output: -15

    return 0;
}
