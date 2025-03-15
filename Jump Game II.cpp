/*You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // Already at the last index

        int jumps = 0, farthest = 0, current_end = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]); // Update the farthest position

            if (i == current_end) { // Time to take a jump
                jumps++;
                current_end = farthest; // Update the current end to the farthest reachable index

                if (current_end >= n - 1) break; // If we can reach the last index, stop
            }
        }
        return jumps;
    }
};

// Main function to test the implementation
int main() {
    Solution solution;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Output: " << solution.jump(nums1) << endl; // Expected: 2

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Output: " << solution.jump(nums2) << endl; // Expected: 2

    return 0;
}


