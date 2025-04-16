/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long pairs = 0, result = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            int val = nums[right];
            // Add new element to frequency map and update pair count
            pairs += freq[val];
            freq[val]++;

            // Shrink the window from the left while pairs >= k
            while (pairs >= k) {
                result += (n - right); // all subarrays from left to end are valid
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }

        return result;
    }
};

// Helper function to run a test case
void runTest(vector<int> nums, int k) {
    Solution sol;
    long long ans = sol.countGood(nums, k);
    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ",");
    }
    cout << "], k = " << k << endl;
    cout << "Output: " << ans << endl << endl;
}

// Main function
int main() {
    runTest({1, 1, 1, 1, 1}, 10);               // Output: 1
    runTest({3, 1, 4, 3, 2, 2, 4}, 2);          // Output: 4
    runTest({1, 2, 1, 2, 1}, 3);                // Extra Test: Output should be number of good subarrays with at least 3 pairs
    return 0;
}
