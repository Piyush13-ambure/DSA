/*You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                // Flip the current and next two elements
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
        }

        // Check if we have any remaining 0s at the end
        for (int i = n - 2; i < n; i++) {
            if (nums[i] == 0) return -1;
        }

        return operations;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;

    vector<int> nums1 = {0, 1, 1, 1, 0, 0};
    cout << "Output: " << sol.minOperations(nums1) << endl; // Output: 3

    vector<int> nums2 = {0, 1, 1, 1};
    cout << "Output: " << sol.minOperations(nums2) << endl; // Output: -1

    return 0;
}
