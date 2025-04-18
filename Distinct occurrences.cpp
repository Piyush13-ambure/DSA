/*You are given two strings txt and pat, find the count of distinct occurrences of pat as a subsequence in txt.*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    int subseqCount(string &txt, string &pat) {
        int m = pat.size();
        int n = txt.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        int MOD = 1e9 + 7;

        // Empty pattern in any txt has 1 match
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (pat[i - 1] == txt[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    string txt, pat;
    cout << "Enter text: ";
    cin >> txt;
    cout << "Enter pattern: ";
    cin >> pat;

    Solution sol;
    int result = sol.subseqCount(txt, pat);

    cout << "Number of distinct subsequences: " << result << endl;

    return 0;
}
