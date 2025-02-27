/*A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> index;
        int n = arr.size();
        int maxLen = 0;
        unordered_map<int, unordered_map<int, int>> dp;

        // Store each element's index for quick lookup
        for (int i = 0; i < n; i++)
            index[arr[i]] = i;

        // Iterate over all pairs (i, j)
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int x = arr[i], y = arr[j];
                int target = x + y;

                // If target exists in arr[], get its index
                if (index.count(target)) {
                    int k = index[target];
                    dp[j][k] = dp[i][j] + 1;
                    maxLen = max(maxLen, dp[j][k]);
                } else {
                    dp[i][j] = 2; // Minimum length sequence [x, y]
                }
            }
        }

        return (maxLen >= 3) ? maxLen : 0;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << sol.lenLongestFibSubseq(arr1) << endl;  // Output: 5

    vector<int> arr2 = {1, 3, 7, 11, 12, 14, 18};
    cout << sol.lenLongestFibSubseq(arr2) << endl;  // Output: 3

    return 0;
}
