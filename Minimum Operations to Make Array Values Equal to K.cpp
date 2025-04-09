/*You are given an integer array nums and an integer k.

An integer h is called valid if all values in the array that are strictly greater than h are identical.

For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.

You are allowed to perform the following operation on nums:

Select an integer h that is valid for the current values in nums.
For each index i where nums[i] > h, set nums[i] to h.
Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Step 1: Check for impossible case
        for (int num : nums) {
            if (num < k) return -1;
        }

        // Step 2: Gather unique values > k
        set<int> unique_vals;
        for (int num : nums) {
            if (num > k) {
                unique_vals.insert(num);
            }
        }

        // Step 3: Count operations needed
        int operations = 0;
        while (!unique_vals.empty()) {
            int max_val = *unique_vals.rbegin(); // largest element
            unique_vals.erase(max_val);

            // Check if all values greater than max_val are identical (they are all max_val)
            bool is_valid = true;
            for (int num : nums) {
                if (num > max_val && num != max_val) {
                    is_valid = false;
                    break;
                }
            }

            if (!is_valid) return -1;

            // Perform the operation: reduce all > max_val to max_val
            for (int &num : nums) {
                if (num > max_val) num = max_val;
            }

            operations++;
        }

        return operations;
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {5,2,5,4,5};
    cout << "Output: " << sol.minOperations(nums1, 2) << endl; // Output: 2

    vector<int> nums2 = {2,1,2};
    cout << "Output: " << sol.minOperations(nums2, 2) << endl; // Output: -1

    vector<int> nums3 = {9,7,5,3};
    cout << "Output: " << sol.minOperations(nums3, 1) << endl; // Output: 4

    return 0;
}
