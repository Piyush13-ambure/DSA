/*Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

*/


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, numSubarray = 0;
        for (auto num : nums) {
            if (num == 0)
                numSubarray++;
            else
                numSubarray = 0;
            ans += numSubarray;
        }
        return ans;
    }
};
