/*You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.*/


#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) : n(size) {
        bit.assign(n + 1, 0);
    }

    void update(int index, int val) {
        index++; // BIT is 1-indexed
        while (index <= n) {
            bit[index] += val;
            index += index & -index;
        }
    }

    int query(int index) {
        index++; // BIT is 1-indexed
        int res = 0;
        while (index > 0) {
            res += bit[index];
            index -= index & -index;
        }
        return res;
    }

    int queryRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; ++i) {
            pos2[nums2[i]] = i;
        }

        // Transform nums1 into mapped positions from nums2
        vector<int> mappedNums(n);
        for (int i = 0; i < n; ++i) {
            mappedNums[i] = pos2[nums1[i]];
        }

        FenwickTree leftBIT(n), rightBIT(n);
        vector<int> rightFreq(n, 0);

        // Initialize right BIT with all frequencies
        for (int i = 0; i < n; ++i) {
            rightBIT.update(mappedNums[i], 1);
        }

        long long result = 0;

        for (int j = 0; j < n; ++j) {
            int mid = mappedNums[j];

            // Remove current element from right BIT
            rightBIT.update(mid, -1);

            // Count how many elements to the left of j are < mid
            int leftSmaller = leftBIT.query(mid - 1);

            // Count how many elements to the right of j are > mid
            int rightGreater = rightBIT.queryRange(mid + 1, n - 1);

            result += (long long)leftSmaller * rightGreater;

            // Add current element to left BIT
            leftBIT.update(mid, 1);
        }

        return result;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {2, 0, 1, 3};
    vector<int> nums2 = {0, 1, 2, 3};
    cout << sol.goodTriplets(nums1, nums2) << endl; // Output: 1

    vector<int> nums3 = {4, 0, 1, 3, 2};
    vector<int> nums4 = {4, 1, 0, 2, 3};
    cout << sol.goodTriplets(nums3, nums4) << endl; // Output: 4
}
