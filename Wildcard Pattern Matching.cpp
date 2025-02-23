/*Given two strings pat and txt which may be of different sizes, You have to return true if the wildcard pattern i.e. pat, matches with txt else return false. All characters of the string pat and txt always belong to the Alphanumeric characters.

The wildcard pattern pat can include the characters '?' and '*'.
'?' – matches any single character.
'*' – matches any sequence of characters (including the empty sequence).

Note: The matching should cover the entire txt (not partial txt). */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty pattern matches empty text
        dp[0][0] = true;
        
        // Filling the first row for patterns with '*'
        for (int i = 1; i <= m; i++) {
            if (pat[i - 1] == '*') dp[i][0] = dp[i - 1][0];
        }
        
        // DP table filling
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (pat[i - 1] == txt[j - 1] || pat[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pat[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string txt1 = "abcde", pat1 = "a?c*";
    cout << sol.wildCard(txt1, pat1) << endl; // Output: true

    string txt2 = "baaabab", pat2 = "a*ab";
    cout << sol.wildCard(txt2, pat2) << endl; // Output: false

    string txt3 = "abc", pat3 = "*";
    cout << sol.wildCard(txt3, pat3) << endl; // Output: true

    return 0;
}
