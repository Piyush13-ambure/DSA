//Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
//Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.
//Answers are guaranteed to fit into a 32-bit integer.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<int> dp(sum + 1, 0);

        // Base case: There is one way to make sum 0 (by choosing no coins)
        dp[0] = 1;

        // Loop through each coin
        for (int coin : coins) {
            for (int i = coin; i <= sum; i++) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[sum];
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 3};
    int sum = 4;

    int result = solution.count(coins, sum);
    cout << "Number of ways to make the sum: " << result << "\n";

    return 0;
}
