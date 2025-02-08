/*Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: empty string and empty pattern match
        dp[0][0] = true;

        // Handle patterns with '*' that match empty strings
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; // Zero occurrence of previous char
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // One or more occurrences
                    }
                }
            }
        }

        return dp[m][n];
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.isMatch("aa", "a") << endl;    // Output: false
    cout << sol.isMatch("aa", "a*") << endl;   // Output: true
    cout << sol.isMatch("ab", ".*") << endl;   // Output: true
    cout << sol.isMatch("mississippi", "mis*is*p*.") << endl; // Output: false
    return 0;
}
