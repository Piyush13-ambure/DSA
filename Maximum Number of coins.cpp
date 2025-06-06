/*We have been given N balloons, each with a number of coins associated with it. On bursting a balloon i, the number of coins gained is equal to A[i-1]*A[i]*A[i+1].
Also, balloons i-1 and i+1 now become adjacent. Find the maximum possible profit earned after bursting all the balloons. Assume an extra 1 at each boundary.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes the array arr[], its size N, and returns the maximum number of coins that can be collected.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxCoins(int N, vector<int> &a) {
        // Padding with 1 at both ends
        vector<int> nums(N + 2, 1);
        for (int i = 0; i < N; ++i) {
            nums[i + 1] = a[i];
        }

        // Create DP table
        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));

        // Interval DP
        for (int len = 1; len <= N; ++len) {
            for (int left = 1; left <= N - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    int coins = nums[left - 1] * nums[k] * nums[right + 1];
                    coins += dp[left][k - 1];
                    coins += dp[k + 1][right];
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }

        return dp[1][N];
    }
};

// Main function for testing
int main() {
    Solution sol;

    // Test Case 1
    int N1 = 2;
    vector<int> a1 = {5, 10};
    cout << "Output: " << sol.maxCoins(N1, a1) << endl; // Expected: 60

    // Test Case 2
    int N2 = 4;
    vector<int> a2 = {3, 1, 5, 8};
    cout << "Output: " << sol.maxCoins(N2, a2) << endl; // Expected: 167

    return 0;
}
