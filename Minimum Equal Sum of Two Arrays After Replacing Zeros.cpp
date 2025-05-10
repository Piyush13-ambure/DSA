/*You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        int z1 = 0, z2 = 0;

        for (int x : nums1) {
            if (x == 0) z1++;
            else s1 += x;
        }

        for (int x : nums2) {
            if (x == 0) z2++;
            else s2 += x;
        }

        // Minimum and maximum achievable sums
        long long min1 = s1 + z1 * 1;
        long long min2 = s2 + z2 * 1;
        long long max1 = s1 + (long long)z1 * 1'000'000;
        long long max2 = s2 + (long long)z2 * 1'000'000;

        // Check if there's any overlap between the ranges
        long long lower = max(min1, min2);
        long long upper = min(max1, max2);

        if (lower > upper) return -1; // No overlap => not possible

        return lower; // This is the minimal achievable equal sum
    }
};

// Driver code for quick testing
int main() {
    Solution sol;
    vector<int> nums1 = {3,2,0,1,0};
    vector<int> nums2 = {6,5,0};
    cout << sol.minSum(nums1, nums2) << endl; // Expected: 12

    vector<int> nums3 = {2,0,2,0};
    vector<int> nums4 = {1,4};
    cout << sol.minSum(nums3, nums4) << endl; // Expected: -1

    return 0;
}
