/*The score of an array is defined as the product of its sum and its length.

For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                ++left;
            }
            
            ans += (right - left + 1);
        }
        
        return ans;
    }
};

int main() {
    int n;
    cin >> n; // size of array
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    long long k;
    cin >> k;
    
    Solution obj;
    cout << obj.countSubarrays(nums, k) << endl;
    
    return 0;
}
