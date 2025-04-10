//Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
//From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).  

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    // Structure for the heap with cost and coordinates
    struct Cell {
        int cost, x, y;
        bool operator>(const Cell& other) const {
            return cost > other.cost;
        }
    };

    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        // Directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            Cell current = pq.top();
            pq.pop();
            int x = current.x, y = current.y, cost = current.cost;

            // If reached destination
            if (x == n - 1 && y == n - 1)
                return cost;

            // Explore neighbors
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int newCost = cost + grid[nx][ny];
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }

        return -1; // Should not reach here for valid grids
    }
};

// Example main function
int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {9, 4, 9, 9},
        {6, 7, 6, 4},
        {8, 3, 3, 7},
        {7, 4, 9, 10}
    };

    vector<vector<int>> grid2 = {
        {4, 4},
        {3, 7}
    };

    cout << "Minimum cost for grid1: " << sol.minimumCostPath(grid1) << endl; // Expected: 43
    cout << "Minimum cost for grid2: " << sol.minimumCostPath(grid2) << endl; // Expected: 14

    return 0;
}
