//Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

//The two identified subsequences A and B can use the same ith character from string s if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of the first "x" must be different in the original string for A and B.


  #include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int LongestRepeatingSubsequence(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == s[j - 1] && i != j) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];  // Include the character
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Exclude the character
                }
            }
        }

        return dp[n][n];  // The answer is in the last cell
    }
};

// Main function to test
int main() {
    Solution sol;
    string str = "aab";

    int result = sol.LongestRepeatingSubsequence(str);
    cout << "Longest Repeating Subsequence Length: " << result << endl;

    return 0;
}
