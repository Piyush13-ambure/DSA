/*Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill DP table
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0)
                    dp[i][j] = j; // Insert all characters of s2 into s1
                else if (j == 0)
                    dp[i][j] = i; // Remove all characters from s1
                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1]; // Characters match, no operation needed
                else
                    dp[i][j] = 1 + min({dp[i - 1][j],      // Remove
                                        dp[i][j - 1],      // Insert
                                        dp[i - 1][j - 1]}); // Replace
            }
        }
        return dp[m][n];
    }
};

// Driver Code
int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    while (T--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);

        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
