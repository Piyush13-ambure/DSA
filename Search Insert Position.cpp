/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;  // Found target, return index
            else if (nums[mid] < target)
                left = mid + 1;  // Move right
            else
                right = mid - 1;  // Move left
        }

        return left;  // The correct insertion index
    }
};

// Main function to test the implementation
int main() {
    vector<int> nums;
    int target, n;

    cout << "Enter the size of the array: ";
    cin >> n;
    nums.resize(n);

    cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    Solution sol;
    int result = sol.searchInsert(nums, target);

    cout << "Output: " << result << endl;
    return 0;
}
