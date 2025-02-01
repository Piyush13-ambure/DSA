//Given two strings wild and pattern. Determine if the given two strings can be matched given that, wild string may contain * and ? but string pattern will not. * and ? can be converted to another character according to the following rule



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool match(string wild, string pattern) {
        int m = wild.size(), n = pattern.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Empty pattern and empty wild string are a match
        dp[0][0] = true;

        // Handle cases where wild starts with '*'
        for (int i = 1; i <= m; i++) {
            if (wild[i - 1] == '*')
                dp[i][0] = dp[i - 1][0]; // '*' can match empty
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (wild[i - 1] == pattern[j - 1] || wild[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (wild[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};

// Main function to test the implementation
int main() {
    string wild, pattern;
    cout << "Enter wildcard string: ";
    cin >> wild;
    cout << "Enter pattern string: ";
    cin >> pattern;

    Solution obj;
    if (obj.match(wild, pattern)) {
        cout << "Match found!" << endl;
    } else {
        cout << "No match found!" << endl;
    }

    return 0;
}
