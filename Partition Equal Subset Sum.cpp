//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

#include <iostream>
#include <vector>
#include <numeric>  // for accumulate

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, it cannot be partitioned equally
        if (total % 2 != 0)
            return false;

        int target = total / 2;
        int n = nums.size();
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test Case 1: " << (solution.canPartition(nums1) ? "true" : "false") << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test Case 2: " << (solution.canPartition(nums2) ? "true" : "false") << endl;

    // You can add more test cases here

    return 0;
}
