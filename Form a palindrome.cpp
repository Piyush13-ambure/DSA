//Given a string, find the minimum number of characters to be inserted to convert it to a palindrome string.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMin(string str) {
        int n = str.length();
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        // DP table for Longest Common Subsequence (LCS) between str and revStr
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (str[i - 1] == revStr[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int lps = dp[n][n]; // Longest Palindromic Subsequence
        return n - lps; // Minimum insertions needed
    }
};

int main() {
    Solution obj;
    string str;
    cout << "Enter the string: ";
    cin >> str;
    
    cout << "Minimum insertions to make it a palindrome: " << obj.countMin(str) << endl;
    return 0;
}
