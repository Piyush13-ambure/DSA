/*Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > minVal) {
                maxDiff = max(maxDiff, nums[i] - minVal);
            } else {
                minVal = nums[i];
            }
        }

        return maxDiff;
    }
};

// -------------------------
// Main function for testing
// -------------------------
int main() {
    Solution sol;

    vector<int> nums1 = {7, 1, 5, 4};
    cout << "Output: " << sol.maximumDifference(nums1) << endl; // Expected: 4

    vector<int> nums2 = {9, 4, 3, 2};
    cout << "Output: " << sol.maximumDifference(nums2) << endl; // Expected: -1

    vector<int> nums3 = {1, 5, 2, 10};
    cout << "Output: " << sol.maximumDifference(nums3) << endl; // Expected: 9

    return 0;
}
