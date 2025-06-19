/*

You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.

Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int start = nums[0];

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] - start > k) {
                count++;
                start = nums[i];
            }
        }

        return count + 1; // +1 for the last group
    }
};

// ------------------ Main Function ------------------
int main() {
    Solution obj;

    vector<int> nums1 = {3, 6, 1, 2, 5};
    int k1 = 2;
    cout << "Output: " << obj.partitionArray(nums1, k1) << endl; // Output: 2

    vector<int> nums2 = {1, 2, 3};
    int k2 = 1;
    cout << "Output: " << obj.partitionArray(nums2, k2) << endl; // Output: 2

    vector<int> nums3 = {2, 2, 4, 5};
    int k3 = 0;
    cout << "Output: " << obj.partitionArray(nums3, k3) << endl; // Output: 3

    return 0;
}
