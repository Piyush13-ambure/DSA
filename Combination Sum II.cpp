/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // If the number exceeds the target, break early
            if (candidates[i] > target) break;

            // Include the number
            combination.push_back(candidates[i]);
            
            // Move to the next index (each number is used only once)
            backtrack(candidates, target - candidates[i], result, combination, i + 1);

            // Backtrack (remove the last added element)
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        
        // Sort the input to handle duplicates and optimize pruning
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, result, combination, 0);
        
        return result;
    }
};

// Main function for testing
int main() {
    Solution sol;
    vector<int> candidates1 = {10,1,2,7,6,1,5};
    int target1 = 8;

    vector<int> candidates2 = {2,5,2,1,2};
    int target2 = 5;

    vector<vector<int>> result1 = sol.combinationSum2(candidates1, target1);
    vector<vector<int>> result2 = sol.combinationSum2(candidates2, target2);

    cout << "Output 1:" << endl;
    for (auto& comb : result1) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]" << endl;
    }

    cout << "\nOutput 2:" << endl;
    for (auto& comb : result2) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}
