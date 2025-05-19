/*You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

A triangle is called equilateral if it has all sides of equal length.
A triangle is called isosceles if it has exactly two sides of equal length.
A triangle is called scalene if all its sides are of different lengths.
Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to simplify triangle inequality check

        // Check if it can form a triangle
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }

        // Check triangle types
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};

// Main function for testing
int main() {
    Solution sol;
    vector<int> nums;

    // Test Case 1
    nums = {3, 3, 3};
    cout << sol.triangleType(nums) << endl; // Output: equilateral

    // Test Case 2
    nums = {3, 4, 5};
    cout << sol.triangleType(nums) << endl; // Output: scalene

    // Test Case 3
    nums = {1, 2, 3};
    cout << sol.triangleType(nums) << endl; // Output: none

    // Test Case 4
    nums = {5, 5, 8};
    cout << sol.triangleType(nums) << endl; // Output: isosceles

    return 0;
}
