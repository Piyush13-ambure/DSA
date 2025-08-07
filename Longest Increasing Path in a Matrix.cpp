/*Given a matrix with n rows and m columns. Your task is to find the length of the longest increasing path in the matrix, here increasing path means that the value in the specified path increases.
For example if a path of length k has values a1, a2, a3, .... ak  , then for every i from [2,k] this condition must hold ai > ai-1.  No cell should be revisited in the path.
From each cell, you can either move in four directions: left, right, up, or down. You are not allowed to move diagonally or move outside the boundary.

*/


class Solution {
  public:
    bool validCell(int i, int j, vector<vector<int>> &matrix, int prev) {
        if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() &&
            matrix[i][j] > prev)
            return true;
        return false;
    }

    int pathRecur(int i, int j, vector<vector<int>> &matrix,
                  vector<vector<int>> &memo) {

        // If answer exists in memo table.
        if (memo[i][j] != -1)
            return memo[i][j];

        // include current cell in answer
        int ans = 1;

        // direction vector to move in 4 directions
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto d : dir) {
            int x = i + d[0], y = j + d[1];

            // Check if the cell is valid
            if (validCell(x, y, matrix, matrix[i][j])) {
                ans = max(ans, 1 + pathRecur(x, y, matrix, memo));
            }
        }

        // Memoize the answer and return it.
        return memo[i][j] = ans;
    }

    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        int ans = 0;

        // Initialize dp table
        vector<vector<int>> memo(n, vector<int>(m, -1));

        // Check longest increasing path
        // for each cell.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, pathRecur(i, j, matrix, memo));
            }
        }

        return ans;
    }
};
