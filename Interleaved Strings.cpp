/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
Interleaving of two strings s1 and s2 is a way to mix their characters to form a new string s3, while maintaining the relative order of characters from s1 and s2. Conditions for interleaving:

Characters from s1 must appear in the same order in s3 as they are in s1.
Characters from s2 must appear in the same order in s3 as they are in s2.
The length of s3 must be equal to the combined length of s1 and s2.*/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        int n = s1.size(), m = s2.size(), l = s3.size();
        if (n + m != l) return false; // Length check

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        // Base case: empty strings interleave to form an empty string
        dp[0][0] = true;

        // Fill first column (using s1 only)
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // Fill first row (using s2 only)
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[n][m];
    }
};

// Main function
int main() {
    Solution sol;
    string s1, s2, s3;
    
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;
    cout << "Enter string s3: ";
    cin >> s3;

    if (sol.isInterleave(s1, s2, s3)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
