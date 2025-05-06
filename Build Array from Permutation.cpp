/*Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        // First pass: encode both old and new values into nums[i]
        for (int i = 0; i < n; i++) {
            int new_val = nums[nums[i]] % n;
            nums[i] = nums[i] + new_val * n;
        }

        // Second pass: extract the new value
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] / n;
        }

        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0, 2, 1, 5, 3, 4};
    vector<int> result1 = sol.buildArray(nums1);
    cout << "Output for [0, 2, 1, 5, 3, 4]: ";
    for (int num : result1) cout << num << " ";
    cout << endl;

    vector<int> nums2 = {5, 0, 1, 2, 3, 4};
    vector<int> result2 = sol.buildArray(nums2);
    cout << "Output for [5, 0, 1, 2, 3, 4]: ";
    for (int num : result2) cout << num << " ";
    cout << endl;

    return 0;
}
