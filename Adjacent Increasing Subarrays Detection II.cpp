/*Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent subarrays of length k each, such that both subarrays are strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where:

Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
The subarrays must be adjacent, meaning b = a + k.
Return the maximum possible value of k.

A subarray is a contiguous non-empty sequence of elements within an array.

 */
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int up = 1, preUp = 0, res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) up++;
            else {
                preUp = up;
                up = 1;
            }
            int half = up >> 1;
            int m = min(preUp, up);
            int candidate = max(half, m);
            if (candidate > res) res = candidate;
        }
        return res;
    }
};
