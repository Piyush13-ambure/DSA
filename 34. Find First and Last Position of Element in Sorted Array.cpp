/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to find first or last occurrence using binary search
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1, result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result = mid;
                if (findFirst)
                    right = mid - 1; // Search in the left half
                else
                    left = mid + 1; // Search in the right half
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
};

// Driver function
int main() {
    Solution sol;
    vector<int> nums;
    int n, target;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter sorted elements: ";
    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    cout << "Enter target: ";
    cin >> target;

    vector<int> result = sol.searchRange(nums, target);
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
