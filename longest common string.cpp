//You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        int maxLength = 0;

        // Create a 2D DP array to store lengths of common substrings
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the DP array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    string s1 = "abcde";
    string s2 = "abfce";

    int result = solution.longestCommonSubstr(s1, s2);
    cout << "Length of the longest common substring: " << result << "\n";

    return 0;
}
