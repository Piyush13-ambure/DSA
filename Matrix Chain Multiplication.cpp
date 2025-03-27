/*Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill DP table
        for (int len = 2; len < n; len++) {  // len is the chain length
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][n - 1];
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<vector<int>> testCases = {
        {2, 1, 3, 4},
        {1, 2, 3, 4, 3},
        {3, 4}
    };

    for (auto &arr : testCases) {
        cout << "Minimum multiplications for arr: ";
        for (int num : arr) cout << num << " ";
        cout << "-> " << solution.matrixMultiplication(arr) << endl;
    }

    return 0;
}
