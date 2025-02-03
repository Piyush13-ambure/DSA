//You are given an array of integers nums. Return the length of the longest subarrayof nums which is either strictly increasing orstrictly decreasing

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int inc_len = 1;  // Length of current increasing subarray
        int dec_len = 1;  // Length of current decreasing subarray
        int max_len = 1;  // Result to store the maximum length of monotonic subarray

        for (int i = 1; i < n; ++i) {
            // Check if the current element is greater than the previous (increasing)
            if (nums[i] > nums[i - 1]) {
                inc_len++;
                dec_len = 1;  // Reset the decreasing subarray length
            }
            // Check if the current element is smaller than the previous (decreasing)
            else if (nums[i] < nums[i - 1]) {
                dec_len++;
                inc_len = 1;  // Reset the increasing subarray length
            }
            else {
                // Reset both lengths if the current element is equal to the previous
                inc_len = 1;
                dec_len = 1;
            }

            // Update the maximum length found so far
            max_len = max(max_len, max(inc_len, dec_len));
        }

        return max_len;
    }
};

// Driver code to test
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 3};
    cout << "Longest Monotonic Subarray Length: " << sol.longestMonotonicSubarray(nums1) << endl;  // Output: 3

    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << "Longest Monotonic Subarray Length: " << sol.longestMonotonicSubarray(nums2) << endl;  // Output: 5

    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Longest Monotonic Subarray Length: " << sol.longestMonotonicSubarray(nums3) << endl;  // Output: 5

    vector<int> nums4 = {1, 3, 2, 4, 5};
    cout << "Longest Monotonic Subarray Length: " << sol.longestMonotonicSubarray(nums4) << endl;  // Output: 3

    return 0;
}
