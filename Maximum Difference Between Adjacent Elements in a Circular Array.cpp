/*Given a circular array nums, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.

 

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;

        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n; // Circular adjacency
            int diff = abs(nums[i] - nums[next]);
            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};

// ---------- Main Function for Testing ----------
int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 4};
    cout << "Output for Example 1: " << sol.maxAdjacentDistance(nums1) << endl; // Expected: 3

    // Example 2
    vector<int> nums2 = {-5, -10, -5};
    cout << "Output for Example 2: " << sol.maxAdjacentDistance(nums2) << endl; // Expected: 5

    return 0;
}
