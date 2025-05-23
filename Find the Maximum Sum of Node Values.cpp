/*There exists an undirected tree with n nodes numbered 0 to n - 1. You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree. You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.

Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
nums[u] = nums[u] XOR k
nums[v] = nums[v] XOR k
Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.

 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long baseSum = 0;
        vector<int> deltas;

        for (int num : nums) {
            baseSum += num;
            int toggled = num ^ k;
            deltas.push_back(toggled - num);
        }

        // Filter positive deltas (beneficial toggles)
        vector<int> positiveDeltas;
        for (int d : deltas) {
            if (d > 0) positiveDeltas.push_back(d);
        }

        // If even number of beneficial toggles, apply all
        if (positiveDeltas.size() % 2 == 0) {
            long long gain = 0;
            for (int d : positiveDeltas) gain += d;
            return baseSum + gain;
        } else {
            // Odd number, remove the smallest loss/gain
            int minDelta = INT_MAX;
            for (int d : deltas) {
                minDelta = min(minDelta, abs(d));
            }

            long long gain = 0;
            for (int d : positiveDeltas) gain += d;
            return baseSum + gain - minDelta;
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 1};
    int k1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}};
    cout << "Output 1: " << sol.maximumValueSum(nums1, k1, edges1) << endl;

    // Example 2
    vector<int> nums2 = {2, 3};
    int k2 = 7;
    vector<vector<int>> edges2 = {{0, 1}};
    cout << "Output 2: " << sol.maximumValueSum(nums2, k2, edges2) << endl;

    // Example 3
    vector<int> nums3 = {7, 7, 7, 7, 7, 7};
    int k3 = 3;
    vector<vector<int>> edges3 = {{0,1}, {0,2}, {0,3}, {0,4}, {0,5}};
    cout << "Output 3: " << sol.maximumValueSum(nums3, k3, edges3) << endl;

    return 0;
}
