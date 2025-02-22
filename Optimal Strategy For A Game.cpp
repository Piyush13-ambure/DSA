//You are given an integer array arr[] of size n. The array elements represent n coins of values v1, v2, ....vn. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the coin's value. You need to determine the maximum possible amount of money you can win if you go first.
//Note: Both the players are playing optimally.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base cases: When there is only one coin, the first player takes it.
        for (int i = 0; i < n; i++) {
            dp[i][i] = arr[i];
        }

        // Fill the DP table diagonally
        for (int gap = 1; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                int pickLeft = arr[i] + min((i + 2 <= j) ? dp[i + 2][j] : 0, (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0);
                int pickRight = arr[j] + min((i <= j - 2) ? dp[i][j - 2] : 0, (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0);
                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        return dp[0][n - 1]; // Maximum value from the whole range
    }
};

int main() {
    vector<int> arr1 = {5, 3, 7, 10};
    vector<int> arr2 = {8, 15, 3, 7};
    
    Solution sol;
    cout << sol.maximumAmount(arr1) << endl; // Output: 15
    cout << sol.maximumAmount(arr2) << endl; // Output: 22

    return 0;
}
