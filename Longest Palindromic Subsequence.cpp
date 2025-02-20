/*Given a string s, return the length of the longest palindromic subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.

A palindromic sequence is a sequence that reads the same forward and backward.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalinSubseq(string &s) {
        int n = s.size();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        // DP table for LCS
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev_s[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];  // The LCS of s and reverse(s)
    }
};

// Driver code
int main() {
    Solution sol;
    string s1 = "bbabcbcab";
    cout << sol.longestPalinSubseq(s1) << endl; // Output: 7

    string s2 = "abcd";
    cout << sol.longestPalinSubseq(s2) << endl; // Output: 1

    string s3 = "agbdba";
    cout << sol.longestPalinSubseq(s3) << endl; // Output: 5

    return 0;
}
