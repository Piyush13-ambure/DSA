/*The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
For eg. below figure represents a chessboard [3 1 4 2].*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> solutions;
        vector<int> current;
        vector<bool> used(n + 1, false); // To avoid duplicate rows

        solve(n, 0, current, used, solutions);
        return solutions;
    }

private:
    void solve(int n, int col, vector<int>& current, vector<bool>& used, vector<vector<int>>& solutions) {
        if (col == n) {
            solutions.push_back(current);
            return;
        }

        for (int row = 1; row <= n; ++row) {
            if (!used[row] && isSafe(current, row, col)) {
                used[row] = true;
                current.push_back(row);
                solve(n, col + 1, current, used, solutions);
                current.pop_back();
                used[row] = false;
            }
        }
    }

    bool isSafe(const vector<int>& current, int row, int col) {
        for (int prevCol = 0; prevCol < col; ++prevCol) {
            int prevRow = current[prevCol];
            if (abs(prevRow - row) == abs(prevCol - col)) {
                return false;
            }
        }
        return true;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> result = sol.nQueen(n);

    cout << "Total solutions: " << result.size() << endl;
    for (const auto& solution : result) {
        for (int val : solution) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
