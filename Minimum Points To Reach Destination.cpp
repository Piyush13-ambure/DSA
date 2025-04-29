/*Given a m*n grid with each cell consisting of a positive, negative, or zero integer. We can move across a cell only if we have positive points. Whenever we pass through a cell, points in that cell are added to our overall points, the task is to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :
1. From a cell (i, j) we can move to (i + 1, j) or (i, j + 1).
2. We cannot move from (i, j) if your overall points at (i, j) are <= 0.
3. We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPoints(int m, int n, vector<vector<int>> points) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Start from bottom-right cell
        dp[m-1][n-1] = max(1, 1 - points[m-1][n-1]);

        // Fill last row
        for (int j = n - 2; j >= 0; j--) {
            dp[m-1][j] = max(1, dp[m-1][j + 1] - points[m-1][j]);
        }

        // Fill last column
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n-1] = max(1, dp[i + 1][n-1] - points[i][n-1]);
        }

        // Fill the rest of the dp table
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int minPointsOnExit = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1, minPointsOnExit - points[i][j]);
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> points1 = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    int m1 = 3, n1 = 3;
    cout << "Minimum Initial Points Required (Example 1): " << sol.minPoints(m1, n1, points1) << endl;

    // Example 2
    vector<vector<int>> points2 = {
        {2, 3},
        {5, 10},
        {10, 30}
    };
    int m2 = 3, n2 = 2;
    cout << "Minimum Initial Points Required (Example 2): " << sol.minPoints(m2, n2, points2) << endl;

    return 0;
}
