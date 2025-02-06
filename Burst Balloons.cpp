//You are given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by an integer array arr[]. You are asked to burst all the balloons. If you burst the ith balloon, you will get (arr[i-1] * arr[i] * arr[i+1]) coins. Return the maximum coins you can collect by bursting the balloons wisely.

//Note: If i-1 or i+1 goes out of the bounds of the array, consider it as if there is a balloon with a 1 painted on it.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &arr) {
        int n = arr.size();
        
        // Add virtual balloons (1s) at the start and end
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; i++)
            balloons[i + 1] = arr[i];

        // DP table
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Solve subproblems of increasing length
        for (int len = 1; len <= n; len++) {
            for (int l = 1; l <= n - len + 1; l++) {
                int r = l + len - 1;
                for (int k = l; k <= r; k++) {
                    int coins = balloons[l - 1] * balloons[k] * balloons[r + 1];
                    coins += dp[l][k - 1] + dp[k + 1][r];  // Left and right subproblems
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }

        return dp[1][n];  // Final answer
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr1 = {5, 10};
    cout << sol.maxCoins(arr1) << endl;  // Output: 60

    vector<int> arr2 = {3, 1, 5, 8};
    cout << sol.maxCoins(arr2) << endl;  // Output: 167

    return 0;
}
