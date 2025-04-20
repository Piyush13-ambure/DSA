/*In the stock market, a person buys a stock and sells it on some future date. You are given an array prices[] representing stock prices on different days and a positive integer k, find out the maximum profit a person can make in at-most k transactions.

A transaction consists of buying and subsequently selling a stock and new transaction can start only when the previous transaction has been completed.*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0) return 0;

        // If k >= n/2, then it's the same as unlimited transactions
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }

        // DP table
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int i = 1; i <= k; ++i) {
            int max_diff = -prices[0];
            for (int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + max_diff);
                max_diff = max(max_diff, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};

int main() {
    Solution sol;
    
    vector<int> prices1 = {10, 22, 5, 80};
    int k1 = 2;
    cout << "Max Profit (Example 1): " << sol.maxProfit(prices1, k1) << endl;

    vector<int> prices2 = {20, 580, 420, 900};
    int k2 = 3;
    cout << "Max Profit (Example 2): " << sol.maxProfit(prices2, k2) << endl;

    vector<int> prices3 = {100, 90, 80, 50, 25};
    int k3 = 1;
    cout << "Max Profit (Example 3): " << sol.maxProfit(prices3, k3) << endl;

    return 0;
}
