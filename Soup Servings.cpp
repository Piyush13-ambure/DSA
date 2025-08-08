/*You have two soups, A and B, each starting with n mL. On every turn, one of the following four serving operations is chosen at random, each with probability 0.25 independent of all previous turns:

pour 100 mL from type A and 0 mL from type B
pour 75 mL from type A and 25 mL from type B
pour 50 mL from type A and 50 mL from type B
pour 25 mL from type A and 75 mL from type B
Note:

There is no operation that pours 0 mL from A and 100 mL from B.
The amounts from A and B are poured simultaneously during the turn.
If an operation asks you to pour more than you have left of a soup, pour all that remains of that soup.
The process stops immediately after any turn in which one of the soups is used up.

Return the probability that A is used up before B, plus half the probability that both soups are used up in the same turn. Answers within 10-5 of the actual answer will be accepted.*/


class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0; // Optimization: probability converges to 1

        int N = (n + 24) / 25; // Convert to units of 25 ml
        vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0.0));

        // Base cases
        dp[0][0] = 0.5; // Both empty
        for (int j = 1; j <= N; ++j) dp[0][j] = 1.0; // A empty first
        for (int i = 1; i <= N; ++i) dp[i][0] = 0.0; // B empty first

        // Fill DP table
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = 0.25 * (
                    dp[max(0, i - 4)][j] +
                    dp[max(0, i - 3)][max(0, j - 1)] +
                    dp[max(0, i - 2)][max(0, j - 2)] +
                    dp[max(0, i - 1)][max(0, j - 3)]
                );
            }
        }

        return dp[N][N];
    }
};
