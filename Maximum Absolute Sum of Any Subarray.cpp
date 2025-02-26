/*You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0, min_sum = 0;
        int max_ending_here = 0, min_ending_here = 0;

        for (int num : nums) {
            // Standard Kadane for max sum
            max_ending_here += num;
            max_sum = max(max_sum, max_ending_here);
            if (max_ending_here < 0) max_ending_here = 0;

            // Kadane for min sum (treating negatives as max)
            min_ending_here += num;
            min_sum = min(min_sum, min_ending_here);
            if (min_ending_here > 0) min_ending_here = 0;
        }

        return max(abs(max_sum), abs(min_sum));
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> nums1 = {1, -3, 2, 3, -4};
    cout << sol.maxAbsoluteSum(nums1) << endl;  // Output: 5

    vector<int> nums2 = {2, -5, 1, -4, 3, -2};
    cout << sol.maxAbsoluteSum(nums2) << endl;  // Output: 8

    return 0;
}
