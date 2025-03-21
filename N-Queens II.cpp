/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;

    void solve(int row, int n, vector<bool>& cols, vector<bool>& leftDiag, vector<bool>& rightDiag) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || leftDiag[row - col + n - 1] || rightDiag[row + col]) continue;

            // Place the queen
            cols[col] = leftDiag[row - col + n - 1] = rightDiag[row + col] = true;

            // Recur to next row
            solve(row + 1, n, cols, leftDiag, rightDiag);

            // Backtrack
            cols[col] = leftDiag[row - col + n - 1] = rightDiag[row + col] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> cols(n, false), leftDiag(2 * n - 1, false), rightDiag(2 * n - 1, false);
        solve(0, n, cols, leftDiag, rightDiag);
        return count;
    }
};

// Driver Code
int main() {
    Solution obj;
    cout << obj.totalNQueens(4) << endl; // Output: 2
    cout << obj.totalNQueens(1) << endl; // Output: 1
    return 0;
}
