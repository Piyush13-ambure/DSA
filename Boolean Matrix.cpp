//Given a boolean matrix mat[], where each cell contains either 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 then all the cells in its ith row and jth column will become 1.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void booleanMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> rowFlag(rows, 0);
        vector<int> colFlag(cols, 0);

        // First pass: Mark rows and columns that need to be updated
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    rowFlag[i] = 1;
                    colFlag[j] = 1;
                }
            }
        }

        // Second pass: Modify the matrix based on rowFlag and colFlag
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rowFlag[i] == 1 || colFlag[j] == 1) {
                    mat[i][j] = 1;
                }
            }
        }
    }
};

// Function to print the matrix
void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {0, 0, 0}};

    Solution sol;
    sol.booleanMatrix(mat);

    cout << "Modified Matrix:\n";
    printMatrix(mat);

    return 0;
}
