//Given 3 strings s1, s2 and s3, the task is to find the length of the longest sub-sequence that is common in all the three given strings.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LCSof3(string& s1, string& s2, string& s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                for (int k = 1; k <= n3; k++) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    } else {
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                    }
                }
            }
        }
        return dp[n1][n2][n3];
    }
};

int main() {
    string s1 = "geeks", s2 = "geeksfor", s3 = "geeksforgeeks";
    Solution sol;
    cout << "Length of LCS of three strings: " << sol.LCSof3(s1, s2, s3) << endl;

    s1 = "abcd", s2 = "efgh", s3 = "ijkl";
    cout << "Length of LCS of three strings: " << sol.LCSof3(s1, s2, s3) << endl;

    return 0;
}
