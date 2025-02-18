//Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        if (arr.empty()) return {};

        // Step 1: Sort intervals by start time
        sort(arr.begin(), arr.end());

        vector<vector<int>> merged;
        merged.push_back(arr[0]); // Initialize with first interval

        // Step 2: Merge overlapping intervals
        for (int i = 1; i < arr.size(); i++) {
            vector<int>& last = merged.back();
            if (arr[i][0] <= last[1]) {  // Overlap case
                last[1] = max(last[1], arr[i][1]);  // Merge
            } else {
                merged.push_back(arr[i]);  // No overlap, add new interval
            }
        }

        return merged;
    }
};

// **Main function to test the code**
int main() {
    Solution sol;

    vector<vector<int>> arr1 = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    vector<vector<int>> result1 = sol.mergeOverlap(arr1);
    cout << "Merged Intervals: ";
    for (auto& interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> arr2 = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    vector<vector<int>> result2 = sol.mergeOverlap(arr2);
    cout << "Merged Intervals: ";
    for (auto& interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
