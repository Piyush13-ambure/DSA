/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        if (n < 4) return result; // Edge case: Not enough elements
        
        sort(nums.begin(), nums.end()); // Step 1: Sort the array

        // Step 2: Iterate through the array with two fixed indices
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for `i`

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for `j`

                int left = j + 1, right = n - 1;

                // Step 3: Two-pointer approach to find pairs
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Move left and right to avoid duplicates
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<vector<int>> result1 = solution.fourSum(nums1, target1);
    
    cout << "Output 1: \n";
    for (const auto& quad : result1) {
        cout << "[";
        for (int num : quad) cout << num << " ";
        cout << "]\n";
    }

    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    vector<vector<int>> result2 = solution.fourSum(nums2, target2);
    
    cout << "\nOutput 2: \n";
    for (const auto& quad : result2) {
        cout << "[";
        for (int num : quad) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
