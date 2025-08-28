/*You are given an n x n square matrix of integers grid. Return the matrix such that:

The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.*/

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<int, priority_queue<int>> maxHeaps;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> minHeaps;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int key = i - j;
                if (key < 0) minHeaps[key].push(grid[i][j]);
                else maxHeaps[key].push(grid[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int key = i - j;
                if (key < 0) {
                    grid[i][j] = minHeaps[key].top();
                    minHeaps[key].pop();
                } else {
                    grid[i][j] = maxHeaps[key].top();
                    maxHeaps[key].pop();
                }
            }
        }
        return grid;
    }
};
