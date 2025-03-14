//You are standing on a point (x, y) and you want to go to the origin (0, 0) by taking steps either left or down i.e. from each point you are allowed to move either in (x-1, y) or (x, y-1). Find the number of paths from point to origin.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ways(int x, int y) {
        const int MOD = 1000000007;
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        // Base case: There is only one way to reach (0,0)
        dp[0][0] = 1;

        // Fill the DP table
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
        
        return dp[x][y];
    }
};

// Driver code
int main() {
    Solution sol;
    int x, y;
    cin >> x >> y;
    cout << sol.ways(x, y) << endl;
    return 0;
}
