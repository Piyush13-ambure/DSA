/*You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        // Step 1: Apply difference array updates from each query
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l] += 1;
            if (r + 1 < n)
                diff[r + 1] -= 1;
        }

        // Step 2: Accumulate to get actual decrement count per index
        vector<int> dec(n, 0);
        dec[0] = diff[0];
        for (int i = 1; i < n; ++i) {
            dec[i] = dec[i - 1] + diff[i];
        }

        // Step 3: Check if each element has exactly the same number of decrements as its value
        for (int i = 0; i < n; ++i) {
            if (dec[i] != nums[i])
                return false;
        }

        return true;
    }
};

// Main function for testing
int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 0, 1};
    vector<vector<int>> queries1 = {{0, 2}};
    cout << (sol.isZeroArray(nums1, queries1) ? "true" : "false") << endl;

    // Example 2
    vector<int> nums2 = {4, 3, 2, 1};
    vector<vector<int>> queries2 = {{1, 3}, {0, 2}};
    cout << (sol.isZeroArray(nums2, queries2) ? "true" : "false") << endl;

    return 0;
}
