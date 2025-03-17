/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.*/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& visited) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip already used numbers
            if (visited[i]) continue;
            
            // Skip duplicates (only pick first occurrence in the recursive level)
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            
            // Mark as visited and add to current permutation
            visited[i] = true;
            current.push_back(nums[i]);
            
            // Recurse
            backtrack(nums, current, visited);
            
            // Backtrack
            visited[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<bool> visited(nums.size(), false);
        vector<int> current;
        backtrack(nums, current, visited);
        return result;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 2};
    vector<vector<int>> res1 = sol.permuteUnique(nums1);

    cout << "Unique Permutations:\n";
    for (auto& perm : res1) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
