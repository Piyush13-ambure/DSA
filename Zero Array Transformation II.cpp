/*You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  // Difference array (size n+1 to handle ri+1 case)

        for (int k = 0; k < queries.size(); k++) {
            int li = queries[k][0], ri = queries[k][1], vali = queries[k][2];

            // Apply range update using the difference array
            diff[li] -= vali;
            if (ri + 1 < n) diff[ri + 1] += vali;

            // Apply difference array to reconstruct nums
            int current_value = nums[0] + diff[0];
            bool is_zero = (current_value == 0);
            nums[0] = current_value;

            for (int i = 1; i < n; i++) {
                diff[i] += diff[i - 1];  // Convert diff array to actual updates
                nums[i] += diff[i];
                if (nums[i] != 0) is_zero = false;
            }

            if (is_zero) return k + 1;  // Minimum queries needed to make nums zero
        }

        return -1;  // If we never get a zero array
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    
    vector<int> nums1 = {2, 0, 2};
    vector<vector<int>> queries1 = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    cout << "Output 1: " << sol.minZeroArray(nums1, queries1) << endl;  // Expected: 2
    
    vector<int> nums2 = {4, 3, 2, 1};
    vector<vector<int>> queries2 = {{1, 3, 2}, {0, 2, 1}};
    cout << "Output 2: " << sol.minZeroArray(nums2, queries2) << endl;  // Expected: -1
    
    return 0;
}
