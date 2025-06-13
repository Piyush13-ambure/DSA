/*You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Binary search for the minimum maximum difference
        int left = 0, right = nums.back() - nums.front();
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFormPairs(nums, mid, p)) {
                result = mid; // Found a valid maximum difference
                right = mid - 1; // Try for a smaller maximum difference
            } else {
                left = mid + 1; // Increase the maximum difference
            }
        }

        return result;
    }

private:
    bool canFormPairs(const vector<int>& nums, int maxDiff, int p) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i++; // Move to the next pair
            }
        }
        return count >= p; // Check if we can form at least p pairs
    }
};

// Main function for testing
int main() {
    Solution solution;
    vector<int> nums1 = {10, 1, 2, 7, 1, 3};
    int p1 = 2;
    int result1 = solution.minimizeMax(nums1, p1);
    cout << "Output for example 1: " << result1 << endl; // Expected output: 1

    vector<int> nums2 = {4, 2, 1, 2};
    int p2 = 1;
    int result2 = solution.minimizeMax(nums2, p2);
    cout << "Output for example 2: " << result2 << endl; // Expected output: 0

    return 0;
}
