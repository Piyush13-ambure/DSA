/*You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

Notes:

When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
Bob can remap a digit to itself, in which case num does not change.
Bob can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.

*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string original = to_string(num);
        int maxNum = INT_MIN;
        int minNum = INT_MAX;

        // Try all digits for maximum
        for (char d = '0'; d <= '9'; ++d) {
            string replaced = original;
            for (char &c : replaced) {
                if (c == d) c = '9';
            }
            maxNum = max(maxNum, stoi(replaced));
        }

        // Try all digits for minimum
        for (char d = '0'; d <= '9'; ++d) {
            string replaced = original;
            for (char &c : replaced) {
                if (c == d) c = '0';
            }
            minNum = min(minNum, stoi(replaced));
        }

        return maxNum - minNum;
    }
};

int main() {
    Solution sol;

    int num1 = 11891;
    cout << "Input: " << num1 << "\nOutput: " << sol.minMaxDifference(num1) << endl;

    int num2 = 90;
    cout << "Input: " << num2 << "\nOutput: " << sol.minMaxDifference(num2) << endl;

    return 0;
}
