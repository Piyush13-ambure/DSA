/*Given a string of S as input. Your task is to write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumNumberOfDeletions(string S) {
        int n = S.length();
        string revS = S;
        reverse(revS.begin(), revS.end());
        
        // DP table for LCS computation
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (S[i - 1] == revS[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lps = dp[n][n];  // Length of the longest palindromic subsequence
        return n - lps;  // Minimum deletions required
    }
};

int main() {
    Solution sol;
    cout << sol.minimumNumberOfDeletions("aebcbda") << endl;  // Output: 2
    cout << sol.minimumNumberOfDeletions("geeksforgeeks") << endl;  // Output: 8
    return 0;
}
