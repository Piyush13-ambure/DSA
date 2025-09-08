/*No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

*/

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int left = i;
            int right = n - i;
            if (!containsZero(left) && !containsZero(right)) {
                return {left, right};
            }
        }
        return {};
    }

    bool containsZero(int n) {
        string str = to_string(n);
        return str.find('0') != string::npos;
    }
};
