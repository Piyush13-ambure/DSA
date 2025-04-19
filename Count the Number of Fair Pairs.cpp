/*Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
*/

class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper, long long ans = 0) {
            for(int i = 0 ; i < nums.size(); i++)
                for(int j = i + 1; j < nums.size(); j++)
                    if(nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper) ++ans;
    
            return ans;
        }
    };
