/*You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int lastMin = -1, lastMax = -1, lastInvalid = -1;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastInvalid = i;
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            int validStart = min(lastMin, lastMax);
            if (validStart > lastInvalid) {
                ans += validStart - lastInvalid;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, minK, maxK;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> minK >> maxK;
    cout << sol.countSubarrays(nums, minK, maxK) << endl;
    return 0;
}
