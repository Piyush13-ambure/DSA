//Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i + k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX); // Initialize dp array with max value
        dp[0] = 0; // Starting stone has zero cost

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= i + k && j < n; j++) {
                dp[j] = min(dp[j], dp[i] + abs(arr[i] - arr[j]));
            }
        }

        return dp[n - 1]; // Minimum cost to reach last stone
    }
};

// **Main function for testing**
int main() {
    Solution sol;
    
    vector<int> arr1 = {10, 30, 40, 50, 20};
    int k1 = 3;
    cout << sol.minimizeCost(k1, arr1) << endl; // Expected Output: 30

    vector<int> arr2 = {10, 20, 10};
    int k2 = 1;
    cout << sol.minimizeCost(k2, arr2) << endl; // Expected Output: 20

    return 0;
}
