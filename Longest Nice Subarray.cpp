/*You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, maxLength = 0, currAND = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // Shrink the window if condition is violated
            while ((currAND & nums[right]) != 0) {
                currAND ^= nums[left]; // Remove nums[left] from OR set
                left++;  // Move left pointer
            }
            
            // Include nums[right] in the OR set
            currAND |= nums[right];

            // Update max length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

// Driver Code
int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 8, 48, 10};
    cout << sol.longestNiceSubarray(nums1) << endl; // Output: 3

    vector<int> nums2 = {3, 1, 5, 11, 13};
    cout << sol.longestNiceSubarray(nums2) << endl; // Output: 1

    return 0;
}
