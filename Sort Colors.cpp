/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};

// Utility function to print the vector
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    Solution sol;

    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Before sorting: ";
    printVector(nums1);
    sol.sortColors(nums1);
    cout << "After sorting: ";
    printVector(nums1);

    vector<int> nums2 = {2, 0, 1};
    cout << "\nBefore sorting: ";
    printVector(nums2);
    sol.sortColors(nums2);
    cout << "After sorting: ";
    printVector(nums2);

    return 0;
}
