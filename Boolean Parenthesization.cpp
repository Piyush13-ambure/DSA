/*You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, int> dp;

    int countWaysUtil(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;  // Invalid case
        if (i == j) {  // Single character case
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (dp.find(key) != dp.end()) return dp[key];

        int ways = 0;
        for (int k = i + 1; k < j; k += 2) {  // Operators are at odd indices
            int leftTrue = countWaysUtil(s, i, k - 1, true);
            int leftFalse = countWaysUtil(s, i, k - 1, false);
            int rightTrue = countWaysUtil(s, k + 1, j, true);
            int rightFalse = countWaysUtil(s, k + 1, j, false);

            if (s[k] == '&') {
                if (isTrue) ways += (leftTrue * rightTrue);
                else ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
            } else if (s[k] == '|') {
                if (isTrue) ways += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
                else ways += (leftFalse * rightFalse);
            } else if (s[k] == '^') {
                if (isTrue) ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
                else ways += (leftTrue * rightTrue) + (leftFalse * rightFalse);
            }
        }

        return dp[key] = ways;
    }

    int countWays(string &s) {
        dp.clear();
        return countWaysUtil(s, 0, s.size() - 1, true);
    }
};

// Main function for testing
int main() {
    Solution sol;
    string s1 = "T|T&F^T";
    cout << "Output: " << sol.countWays(s1) << endl;  // Expected: 4

    string s2 = "T^F|F";
    cout << "Output: " << sol.countWays(s2) << endl;  // Expected: 2

    return 0;
}
