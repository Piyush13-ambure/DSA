//Given two integer values n and r, the task is to find the value of Binomial Coefficient nCrA binomial coefficient nCr can be defined as the coefficient of x^r in the expansion of (1 + x)^n.A binomial coefficient nCr also gives the number of ways, disregarding order, that r objects can be chosen from among n objects more formally, the number of r-element subsets (or r-combinations) of a n-element set.#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate nCr (Binomial Coefficient)
    int nCr(int n, int r) {
        if (r > n) return 0; // Not possible to choose more than available
        if (r == 0 || r == n) return 1; // Base cases

        // Create a DP table to store values of nCr
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

        // Fill the table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= min(i, r); j++) {
                if (j == 0 || j == i) {
                    dp[i][j] = 1; // Base cases: nC0 = 1 and nCn = 1
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // Recursive relation
                }
            }
        }

        return dp[n][r];
    }
};

int main() {
    int n, r;
    cout << "Enter the values of n and r: ";
    cin >> n >> r;

    Solution sol;
    int result = sol.nCr(n, r);

    cout << "The value of " << n << "C" << r << " is: " << result << endl;

    return 0;
}
