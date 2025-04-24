/*You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.*/

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnt;
        int n = nums.size();
        int right = 0;
        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinct_count = distinct.size();

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                int remove = nums[left - 1];
                cnt[remove]--;
                if (cnt[remove] == 0) {
                    cnt.erase(remove);
                }
            }
            while (right < n && cnt.size() < distinct_count) {
                int add = nums[right];
                cnt[add]++;
                right++;
            }
            if (cnt.size() == distinct_count) {
                res += (n - right + 1);
            }
        }
        return res;
    }
};
