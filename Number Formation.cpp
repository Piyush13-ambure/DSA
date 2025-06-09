/*Given three integers x, y, and z, the task is to find the sum of all the numbers formed by 
having 4 at most x times, having 5 at most y times, and having 6 at most z times as a digit.

Note: Output the sum modulo 109+7.

Your Task:  
You don't need to read input or print anything. Complete the function getSum() which takes X, Y and Z as input parameters and returns the integer value
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getSum(int X, int Y, int Z) {
        const int MOD = 1e9 + 7;

        vector<vector<vector<long long>>> dp(X+1, vector<vector<long long>>(Y+1, vector<long long>(Z+1, 0)));
        vector<vector<vector<long long>>> count(X+1, vector<vector<long long>>(Y+1, vector<long long>(Z+1, 0)));

        count[0][0][0] = 1;

        for (int i = 0; i <= X; ++i) {
            for (int j = 0; j <= Y; ++j) {
                for (int k = 0; k <= Z; ++k) {
                    if (i > 0) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]*10 + 4 * count[i-1][j][k]) % MOD;
                        count[i][j][k] = (count[i][j][k] + count[i-1][j][k]) % MOD;
                    }
                    if (j > 0) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k]*10 + 5 * count[i][j-1][k]) % MOD;
                        count[i][j][k] = (count[i][j][k] + count[i][j-1][k]) % MOD;
                    }
                    if (k > 0) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j][k-1]*10 + 6 * count[i][j][k-1]) % MOD;
                        count[i][j][k] = (count[i][j][k] + count[i][j][k-1]) % MOD;
                    }
                }
            }
        }

        return dp[X][Y][Z] % MOD;
    }
};

// Main function for testing
int main() {
    Solution sol;

    int X1 = 1, Y1 = 1, Z1 = 1;
    cout << "Output for X=1, Y=1, Z=1: " << sol.getSum(X1, Y1, Z1) << endl;

    int X2 = 0, Y2 = 0, Z2 = 0;
    cout << "Output for X=0, Y=0, Z=0: " << sol.getSum(X2, Y2, Z2) << endl;

    return 0;
}
