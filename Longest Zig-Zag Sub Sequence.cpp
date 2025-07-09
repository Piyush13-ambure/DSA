/*Given an array nums of n positive integers. The task is to find the longest Zig-Zag subsequence problem such that all elements of this are alternating (numsi-1 < numsi > numsi+1 or numsi-1 > numsi < numsi+1).

Your Task:
You don't need to read or print anyhting. Your task is to complete the function ZigZagMaxLength() which takes the sequence  nums as input parameter and returns the maximum length of alternating sequence.
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ZigZagMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;

        int up = 1, down = 1; // Every single element is itself a ZigZag of length 1

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
            // If nums[i] == nums[i-1], do nothing
        }

        return max(up, down);
    }
};

// Example usage
int main() {
    Solution obj;
    vector<int> nums1 = {1, 5, 4};
    vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};

    cout << "Example 1 Output: " << obj.ZigZagMaxLength(nums1) << endl;  // Expected: 3
    cout << "Example 2 Output: " << obj.ZigZagMaxLength(nums2) << endl;  // Expected: 7

    return 0;
}
