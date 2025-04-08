/*You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:

Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        while (true) {
            unordered_set<int> seen;
            bool hasDuplicate = false;

            for (int num : nums) {
                if (seen.count(num)) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(num);
            }

            if (!hasDuplicate) break;

            // Remove first 3 elements
            operations++;
            if (nums.size() <= 3) {
                nums.clear();
            } else {
                nums.erase(nums.begin(), nums.begin() + 3);
            }
        }

        return operations;
    }
};

// Example Usage
int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,4,2,3,3,5,7};
    cout << "Output: " << sol.minimumOperations(nums1) << endl; // 2

    vector<int> nums2 = {4,5,6,4,4};
    cout << "Output: " << sol.minimumOperations(nums2) << endl; // 2

    vector<int> nums3 = {6,7,8,9};
    cout << "Output: " << sol.minimumOperations(nums3) << endl; // 0

    return 0;
}
