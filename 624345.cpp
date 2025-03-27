/*Given a string s, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int palPartition(string &s) {
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        // Precompute palindrome substrings
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 1 || len == 2) {
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                    }
                }
            }
        }

        // DP to find minimum cuts
        for (int i = 0; i < n; i++) {
            if (isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = i;
                for (int j = 0; j < i; j++) {
                    if (isPalindrome[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<string> testCases = {"geek", "aaaa", "ababbbabbababa"};

    for (string &s : testCases) {
        cout << "Minimum cuts needed for \"" << s << "\": " << solution.palPartition(s) << endl;
    }

    return 0;
}
