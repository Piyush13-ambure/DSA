/*Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n=nums.size();
        int zeros=0, ans=0;
        for(int l=0, r=0; r<n; r++){
            zeros+=(nums[r]==0);
            zeros-=(zeros>1 && nums[l++]==0);
            ans=max(ans, r-l);
        }
        return ans; 
    }
};
