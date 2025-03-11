/*Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given targe*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // There is always one way to make sum 0, which is by selecting an empty subset.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                if (arr[i - 1] <= sum) {
                    dp[i][sum] = dp[i - 1][sum] + dp[i - 1][sum - arr[i - 1]];
                } else {
                    dp[i][sum] = dp[i - 1][sum];
                }
            }
        }

        return dp[n][target];
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {5, 2, 3, 10, 6, 8};
    int target1 = 10;
    cout << "Output: " << sol.perfectSum(arr1, target1) << endl;

    vector<int> arr2 = {2, 5, 1, 4, 3};
    int target2 = 10;
    cout << "Output: " << sol.perfectSum(arr2, target2) << endl;

    vector<int> arr3 = {5, 7, 8};
    int target3 = 3;
    cout << "Output: " << sol.perfectSum(arr3, target3) << endl;

    vector<int> arr4 = {35, 2, 8, 22};
    int target4 = 0;
    cout << "Output: " << sol.perfectSum(arr4, target4) << endl;

    return 0;
}
