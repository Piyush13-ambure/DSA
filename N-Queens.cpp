/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& solutions,
               vector<int>& columns, vector<int>& main_diagonal, vector<int>& anti_diagonal) {
        if (row == n) { // Base case: All n queens placed
            solutions.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (columns[col] || main_diagonal[row - col + (n - 1)] || anti_diagonal[row + col])
                continue; // If under attack, skip this column
            
            // Place the queen
            board[row][col] = 'Q';
            columns[col] = main_diagonal[row - col + (n - 1)] = anti_diagonal[row + col] = 1;
            
            // Recur to place queen in the next row
            solve(row + 1, n, board, solutions, columns, main_diagonal, anti_diagonal);
            
            // Backtrack
            board[row][col] = '.';
            columns[col] = main_diagonal[row - col + (n - 1)] = anti_diagonal[row + col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); // Initialize an empty board
        vector<int> columns(n, 0), main_diagonal(2 * n - 1, 0), anti_diagonal(2 * n - 1, 0);

        solve(0, n, board, solutions, columns, main_diagonal, anti_diagonal);
        return solutions;
    }
};

// Driver function
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    Solution obj;
    vector<vector<string>> res = obj.solveNQueens(n);
    
    for (const auto& solution : res) {
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    return 0;
}
