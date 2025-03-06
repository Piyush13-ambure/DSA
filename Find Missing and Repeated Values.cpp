/*You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        vector<int> count(N + 1, 0);
        int repeated = -1, missing = -1;

        // Count occurrences of each number in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }

        // Find the repeated and missing numbers
        for (int i = 1; i <= N; i++) {
            if (count[i] == 2) repeated = i;
            if (count[i] == 0) missing = i;
        }

        return {repeated, missing};
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    vector<vector<int>> grid1 = {{1, 3}, {2, 2}};
    vector<vector<int>> grid2 = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};

    vector<int> result1 = sol.findMissingAndRepeatedValues(grid1);
    vector<int> result2 = sol.findMissingAndRepeatedValues(grid2);

    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}
