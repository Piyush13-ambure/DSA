/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) 
                return mid;

            // Check which part is sorted
            if (nums[left] <= nums[mid]) { // Left half is sorted
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1; // Search in left half
                else
                    left = mid + 1; // Search in right half
            } else { // Right half is sorted
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1; // Search in right half
                else
                    right = mid - 1; // Search in left half
            }
        }

        return -1; // Target not found
    }
};

// Main function
int main() {
    vector<int> nums;
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter the elements of the array: ";
    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter the target value: ";
    cin >> target;

    Solution sol;
    int result = sol.search(nums, target);

    cout << "Output: " << result << endl;
    return 0;
}
