//Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSquare(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        if (rows == 0 || cols == 0) return 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int max_side = 0;

        // Fill the DP table
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;  // First row/column remains the same
                    } else {
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }

        return max_side;
    }
};

int main() {
    vector<vector<int>> mat = {{0, 1, 1, 0, 1}, 
                               {1, 1, 0, 1, 0},
                               {0, 1, 1, 1, 0},
                               {1, 1, 1, 1, 0},
                               {1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0}};

    Solution sol;
    int result = sol.maxSquare(mat);
    cout << "Maximum side length of square sub-matrix with all 1s: " << result << endl;

    return 0;
}
