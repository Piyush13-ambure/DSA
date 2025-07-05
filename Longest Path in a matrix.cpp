/*Given a matrix, find the maximum length path (starting from any cell) such that all cells along the path are in strictly increasing order.
We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1).
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int maxPath = 0;
        
        // Check all cells as a starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxPath = max(maxPath, dfs(matrix, dp, i, j, rows, cols));
            }
        }
        
        return maxPath;
    }

private:
    // Directions: up, down, left, right
    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int rows, int cols) {
        if (dp[i][j] != -1) return dp[i][j];  // Memoization

        int maxLen = 1; // At least the cell itself
        for (auto dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            if (x >= 0 && x < rows && y >= 0 && y < cols && matrix[x][y] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(matrix, dp, x, y, rows, cols));
            }
        }

        dp[i][j] = maxLen;
        return maxLen;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {{1, 2, 9}, {5, 3, 8}, {4, 6, 7}};
    cout << "Output: " << sol.longestIncreasingPath(matrix1) << endl;  // Expected: 7

    vector<vector<int>> matrix2 = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    cout << "Output: " << sol.longestIncreasingPath(matrix2) << endl;  // Expected: 4

    vector<vector<int>> matrix3 = {{3,2,1,4,9,10,8,6,7}, {10,5,1,5,10,2,6,7,5}, {2,5,6,2,4,6,10,10,7}};
    cout << "Output: " << sol.longestIncreasingPath(matrix3) << endl;  // Expected: 4

    return 0;
}
