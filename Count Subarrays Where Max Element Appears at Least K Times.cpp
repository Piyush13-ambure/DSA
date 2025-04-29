/*You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        long long result = 0;
        int left = 0, count = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == max_val)
                count++;

            while (count >= k) {
                result += (n - right); // All subarrays starting from `left` to `n-1`
                if (nums[left] == max_val)
                    count--;
                left++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 3, 2, 3, 3};
    int k1 = 2;
    cout << "Output (Example 1): " << sol.countSubarrays(nums1, k1) << endl;

    // Example 2
    vector<int> nums2 = {1, 4, 2, 1};
    int k2 = 3;
    cout << "Output (Example 2): " << sol.countSubarrays(nums2, k2) << endl;

    return 0;
}
