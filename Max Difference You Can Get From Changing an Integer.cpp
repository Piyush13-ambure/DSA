/*You are given an integer num. You will apply the following steps to num two separate times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). Note y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.

Return the max difference between a and b.

Note that neither a nor b may have any leading zeros, and must not be 0.

 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;

        // Maximize `a`: Replace first digit that is not 9 with 9
        for (char& c : a) {
            if (c != '9') {
                char x = c;
                for (char& ch : a) {
                    if (ch == x) ch = '9';
                }
                break;
            }
        }

        // Minimize `b`: Replace first digit with smallest possible (1 if first, 0 otherwise)
        for (int i = 0; i < b.size(); ++i) {
            if (i == 0 && b[i] != '1') {
                char x = b[i];
                for (char& ch : b) {
                    if (ch == x) ch = '1';
                }
                break;
            } else if (i > 0 && b[i] != '0' && b[i] != b[0]) {
                char x = b[i];
                for (char& ch : b) {
                    if (ch == x) ch = '0';
                }
                break;
            }
        }

        return stoi(a) - stoi(b);
    }
};

// Driver code
int main() {
    Solution sol;

    int num1 = 555;
    cout << "Example 1 Output: " << sol.maxDiff(num1) << endl;

    int num2 = 9;
    cout << "Example 2 Output: " << sol.maxDiff(num2) << endl;

    int num3 = 123456;
    cout << "Example 3 Output: " << sol.maxDiff(num3) << endl;

    return 0;
}
