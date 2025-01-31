//Given two strings s1 and s2, find the length of the smallest string which has both s1 and s2 as its sub-sequences.
//Note: s1 and s2 can have both uppercase and lowercase English letters.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find length of shortest common supersequence
    int shortestCommonSupersequence(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Compute LCS using bottom-up DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];  // Match found
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Exclude one character
            }
        }

        // Compute SCS length
        return n + m - dp[n][m];
    }
};

int main() {
    Solution sol;
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout << sol.shortestCommonSupersequence(s1, s2) << endl; // Output: 9
    return 0;
}
