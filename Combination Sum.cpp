/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);  // Found a valid combination
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;  // Skip if exceeding target
            
            path.push_back(candidates[i]);  // Choose the element
            backtrack(i, candidates, target - candidates[i], path, result);  // Allow reuse of same element
            path.pop_back();  // Undo choice (backtrack)
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(0, candidates, target, path, result);
        return result;
    }
};

// Driver Code
int main() {
    Solution obj;
    
    vector<int> candidates1 = {2,3,6,7};
    int target1 = 7;
    vector<vector<int>> result1 = obj.combinationSum(candidates1, target1);
    
    cout << "Output for [2,3,6,7], target = 7:\n";
    for (auto& v : result1) {
        cout << "[";
        for (int num : v) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
