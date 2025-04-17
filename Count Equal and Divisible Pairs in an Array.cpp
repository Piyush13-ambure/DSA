/*Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

// -------- MAIN FUNCTION --------
int main() {
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;

    Solution obj;
    int result = obj.countPairs(nums, k);

    cout << "Output: " << result << endl;

    return 0;
}
