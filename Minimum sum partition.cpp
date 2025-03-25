/*Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int target = totalSum / 2;
        
        // DP array to track achievable sums
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base Case: Sum 0 is always achievable
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        // Filling DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (j >= arr[i - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Find the largest sum ≤ totalSum / 2 that is achievable
        int S1 = 0;
        for (int j = target; j >= 0; j--) {
            if (dp[n][j]) {
                S1 = j;
                break;
            }
        }

        // Return the minimum possible difference
        return totalSum - 2 * S1;
    }
};

// Driver code
int main() {
    vector<int> arr = {1, 6, 11, 5};
    Solution sol;
    cout << sol.minDifference(arr) << endl;  // Output: 1
    
    vector<int> arr2 = {1, 4};
    cout << sol.minDifference(arr2) << endl;  // Output: 3

    vector<int> arr3 = {1};
    cout << sol.minDifference(arr3) << endl;  // Output: 1

    return 0;
}
