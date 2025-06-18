/*You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i += 3) {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            // Check the condition for all pairs in the group
            if (c - a > k) {
                return {}; // Invalid group found
            }

            result.push_back({a, b, c});
        }

        return result;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k1 = 2;
    auto res1 = sol.divideArray(nums1, k1);
    cout << "Output 1:\n";
    if (res1.empty()) cout << "[]\n";
    for (const auto& group : res1) {
        cout << "[";
        for (int num : group) cout << num << " ";
        cout << "]\n";
    }

    vector<int> nums2 = {2, 4, 2, 2, 5, 2};
    int k2 = 2;
    auto res2 = sol.divideArray(nums2, k2);
    cout << "Output 2:\n";
    if (res2.empty()) cout << "[]\n";
    for (const auto& group : res2) {
        cout << "[";
        for (int num : group) cout << num << " ";
        cout << "]\n";
    }

    vector<int> nums3 = {4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11};
    int k3 = 14;
    auto res3 = sol.divideArray(nums3, k3);
    cout << "Output 3:\n";
    if (res3.empty()) cout << "[]\n";
    for (const auto& group : res3) {
        cout << "[";
        for (int num : group) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
