/*Given an integer array nums, find the subarray with the largest sum, and return its sum.*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];  // Store the maximum subarray sum
        int currentSum = nums[0]; // Current subarray sum
        
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]); // Extend or restart subarray
            maxSum = max(maxSum, currentSum); // Update maximum sum
        }
        
        return maxSum;
    }
};

// Main function for testing
int main() {
    Solution sol;
    
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums1) << endl; // Expected output: 6

    vector<int> nums2 = {1};
    cout << sol.maxSubArray(nums2) << endl; // Expected output: 1

    vector<int> nums3 = {5,4,-1,7,8};
    cout << sol.maxSubArray(nums3) << endl; // Expected output: 23

    return 0;
}
