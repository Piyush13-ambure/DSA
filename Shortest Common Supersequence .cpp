/*Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        
        // Step 1: Compute LCS using DP
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Backtrack to build the SCS
        string result = "";
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];  // Take from LCS
                i--; j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result += str1[i - 1];  // Take from str1
                i--;
            } else {
                result += str2[j - 1];  // Take from str2
                j--;
            }
        }

        // Add remaining characters from str1 and str2
        while (i > 0) {
            result += str1[i - 1];
            i--;
        }
        while (j > 0) {
            result += str2[j - 1];
            j--;
        }

        // Step 3: Reverse the string to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    string str1, str2;
    cin >> str1 >> str2;

    cout << sol.shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}
