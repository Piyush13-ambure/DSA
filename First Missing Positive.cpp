/*Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place each number in its correct position
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Step 3: If all numbers are correctly placed, return n + 1
        return n + 1;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 0};
    cout << "Output: " << sol.firstMissingPositive(nums1) << endl; // Expected: 3

    vector<int> nums2 = {3, 4, -1, 1};
    cout << "Output: " << sol.firstMissingPositive(nums2) << endl; // Expected: 2

    vector<int> nums3 = {7, 8, 9, 11, 12};
    cout << "Output: " << sol.firstMissingPositive(nums3) << endl; // Expected: 1

    return 0;
}
