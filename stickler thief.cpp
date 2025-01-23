//Stickler the thief wants to loot money from n houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot. Given an array, arr[] where arr[i] represents the amount of money in the i-th house, find the maximum amount he can loot.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the maximum money the thief can get
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();

        // Base cases
        if (n == 0) return 0; // No houses to loot
        if (n == 1) return arr[0]; // Only one house to loot

        // DP array to store the maximum money that can be looted up to each house
        vector<int> dp(n);

        // Initialize the first two houses
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        // Fill the DP array
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
        }

        // The maximum money that can be looted is stored in dp[n-1]
        return dp[n - 1];
    }
};

int main() {
    Solution solution;

    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout << "Maximum money the thief can loot: " << solution.findMaxSum(arr) << endl;

    return 0;
}
