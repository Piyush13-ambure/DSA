/*You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        vector<long long> dp(n + 1);
        dp[0] = 1; // Empty board
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; ++i) {
            dp[i] = (2 * dp[i - 3] % MOD + dp[i - 1] + dp[i - 2]) % MOD;
        }

        return dp[n];
    }
};

// Main function to test
int main() {
    Solution sol;
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Number of ways to tile 2 x " << n << " board: " << sol.numTilings(n) << endl;
    return 0;
}
