/*You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2; // Total pairs in array

        unordered_map<int, long long> freq;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            goodPairs += freq[diff]; // Add the number of previous occurrences
            freq[diff]++; // Update frequency of diff[i]
        }

        return totalPairs - goodPairs; // Bad pairs = Total pairs - Good pairs
    }
};
