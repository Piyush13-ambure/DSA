/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2]; // Initialize with the first three elements

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // Update closest sum if it's better
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum < target) {
                    left++; // Move left pointer to increase sum
                } else if (sum > target) {
                    right--; // Move right pointer to decrease sum
                } else {
                    return sum; // If exact match, return immediately
                }
            }
        }

        return closest;
    }
};

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    Solution sol;
    cout << "Closest sum: " << sol.threeSumClosest(nums, target) << endl;

    return 0;
}
