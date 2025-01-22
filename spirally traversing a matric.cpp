//You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to traverse the matrix in spiral form
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> result;
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; i++) {
                result.push_back(mat[top][i]);
            }
            top++; // Move down to the next row

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++) {
                result.push_back(mat[i][right]);
            }
            right--; // Move left to the next column

            // Traverse from right to left if rows remain
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(mat[bottom][i]);
                }
                bottom--; // Move up to the previous row
            }

            // Traverse from bottom to top if columns remain
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(mat[i][left]);
                }
                left++; // Move right to the next column
            }
        }

        return result;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    vector<vector<int>> mat1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result = solution.spirallyTraverse(mat1);

    cout << "Spiral traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
