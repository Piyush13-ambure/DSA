/*Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer to track position for non-val elements
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i]; // Place non-val elements in front
            }
        }
        
        return k; // Return the count of non-val elements
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int k1 = sol.removeElement(nums1, val1);
    cout << "Output: " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) cout << nums1[i] << (i < k1 - 1 ? ", " : "");
    cout << "]" << endl;
    
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = sol.removeElement(nums2, val2);
    cout << "Output: " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) cout << nums2[i] << (i < k2 - 1 ? ", " : "");
    cout << "]" << endl;

    return 0;
}
