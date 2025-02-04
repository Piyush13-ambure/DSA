//Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

//A subarray is defined as a contiguous sequence of numbers in an array.

//A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Add to currentSum if the current element is larger than the previous one
            if (i == 0 || nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                // Update maxSum if the currentSum is greater
                maxSum = max(maxSum, currentSum);
                // Reset currentSum to the current element
                currentSum = nums[i];
            }
        }
        
        // Return the maximum sum at the end (after last element comparison)
        return max(maxSum, currentSum);
    }
};

int main() {
    vector<int> nums = {10, 20, 30, 5, 10, 50};
    Solution obj;
    cout << obj.maxAscendingSum(nums) << endl;  // Output: 65 (for subarray [5, 10, 50])
    return 0;
}
