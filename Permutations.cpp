/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, result, start + 1);
            swap(nums[start], nums[i]); // backtrack
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> result = sol.permute(nums);
    
    for (const auto& perm : result) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}
