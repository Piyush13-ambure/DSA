/*An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the dominant element using Boyer-Moore's Voting Algorithm
        int candidate = nums[0], count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else {
                count += (num == candidate) ? 1 : -1;
            }
        }

        // Step 2: Count total occurrences of the dominant element
        int totalCount = count_if(nums.begin(), nums.end(), [&](int x) { return x == candidate; });

        // Step 3: Find the minimum index of a valid split
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) {
                leftCount++;
            }
            int leftSize = i + 1;
            int rightSize = n - leftSize;

            // Check if candidate is dominant in both halves
            if (leftCount * 2 > leftSize && (totalCount - leftCount) * 2 > rightSize) {
                return i;
            }
        }

        return -1;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<vector<int>> testCases = {
        {1,2,2,2},
        {2,1,3,1,1,1,7,1,2,1},
        {3,3,3,3,7,2,2}
    };

    for (auto &nums : testCases) {
        cout << "Minimum index of valid split: " << solution.minimumIndex(nums) << endl;
    }

    return 0;
}
