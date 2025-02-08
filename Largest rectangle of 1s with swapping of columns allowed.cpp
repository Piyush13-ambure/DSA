//Given a matrix mat of size R*C with 0 and 1s, find the largest rectangle of all 1s in the matrix. The rectangle can be formed by swapping any pair of columns of given matrix.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxArea(vector<vector<int>> &mat, int R, int C) {
        vector<vector<int>> height(R, vector<int>(C, 0));

        // Step 1: Compute height matrix
        for (int j = 0; j < C; j++) {
            for (int i = 0; i < R; i++) {
                if (mat[i][j] == 1) {
                    height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
                } else {
                    height[i][j] = 0;
                }
            }
        }

        int maxArea = 0;

        // Step 2: Compute max area row-wise after sorting
        for (int i = 0; i < R; i++) {
            // Step 2.1: Sort row in non-increasing order
            vector<int> sortedHeight = height[i];
            sort(sortedHeight.rbegin(), sortedHeight.rend());

            // Step 2.2: Compute max area for this row
            for (int j = 0; j < C; j++) {
                maxArea = max(maxArea, sortedHeight[j] * (j + 1));
            }
        }

        return maxArea;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<vector<int>> mat1 = {
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0}
    };
    cout << sol.maxArea(mat1, 3, 5) << endl;  // Output: 6

    vector<vector<int>> mat2 = {
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1}
    };
    cout << sol.maxArea(mat2, 4, 5) << endl;  // Output: 9

    return 0;
}
