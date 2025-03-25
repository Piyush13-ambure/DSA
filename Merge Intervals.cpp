//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (const auto& interval : intervals) {
            // If merged is empty or there is no overlap, add the interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Merge by updating the end time
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<vector<int>> intervals1 = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result1 = sol.merge(intervals1);
    
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> intervals2 = {{1,4}, {4,5}};
    vector<vector<int>> result2 = sol.merge(intervals2);
    
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
