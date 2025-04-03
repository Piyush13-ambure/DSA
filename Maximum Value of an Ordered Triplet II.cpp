//You are given a 0-indexed integer array nums.

//Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

//The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        long long maxVal = 0;
        int maxPrefix = nums[0];
        vector<int> maxSuffix(n, 0);

        // Compute the max suffix array (max value from index j+1 to n-1)
        maxSuffix[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; --i) {
            maxSuffix[i] = max(maxSuffix[i + 1], nums[i]);
        }

        // Iterate over all j as the middle element
        for (int j = 1; j < n - 1; ++j) {
            if (maxPrefix > nums[j]) {
                long long tripletValue = (long long)(maxPrefix - nums[j]) * maxSuffix[j + 1];
                maxVal = max(maxVal, tripletValue);
            }
            maxPrefix = max(maxPrefix, nums[j]); // Update maxPrefix for next iteration
        }

        return maxVal;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    vector<int> nums1 = {12, 6, 1, 2, 7};
    vector<int> nums2 = {1, 10, 3, 4, 19};
    vector<int> nums3 = {1, 2, 3};

    cout << sol.maximumTripletValue(nums1) << endl; // Output: 77
    cout << sol.maximumTripletValue(nums2) << endl; // Output: 133
    cout << sol.maximumTripletValue(nums3) << endl; // Output: 0

    return 0;
}
