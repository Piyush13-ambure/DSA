/*You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFormZeroArray(const vector<int>& nums, const vector<vector<int>>& queries, int keep) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < keep; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            diff[l] += 1;
            if (r + 1 < n) diff[r + 1] -= 1;
        }

        vector<int> coverage(n, 0);
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += diff[i];
            coverage[i] = curr;
            if (coverage[i] < nums[i]) return false;
        }
        return true;
    }

    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0;
        int right = queries.size();
        int ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int keep = queries.size() - mid;

            if (canFormZeroArray(nums, queries, keep)) {
                ans = mid; // mid queries can be removed
                left = mid + 1; // try to remove more
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

// Main function to test the code
int main() {
    Solution sol;

    vector<int> nums1 = {2, 0, 2};
    vector<vector<int>> queries1 = {{0, 2}, {0, 2}, {1, 1}};
    cout << "Example 1 Output: " << sol.maxRemoval(nums1, queries1) << endl;

    vector<int> nums2 = {1, 1, 1, 1};
    vector<vector<int>> queries2 = {{1, 3}, {0, 2}, {1, 3}, {1, 2}};
    cout << "Example 2 Output: " << sol.maxRemoval(nums2, queries2) << endl;

    vector<int> nums3 = {1, 2, 3, 4};
    vector<vector<int>> queries3 = {{0, 3}};
    cout << "Example 3 Output: " << sol.maxRemoval(nums3, queries3) << endl;

    return 0;
}
