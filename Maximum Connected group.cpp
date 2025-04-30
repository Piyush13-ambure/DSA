/*You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent(top, bottom, left, right) to each other and both have the same value.

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    // Perform DFS to mark the component and count its size
    int dfs(int i, int j, int id, vector<vector<int>>& grid, vector<vector<int>>& comp) {
        comp[i][j] = id;
        int size = 1;

        for (auto& d : directions) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1 && comp[ni][nj] == 0) {
                size += dfs(ni, nj, id, grid, comp);
            }
        }
        return size;
    }

    int MaxConnection(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> comp(n, vector<int>(n, 0));
        unordered_map<int, int> area; // component id -> size
        int id = 1;

        // Step 1: label all components and calculate their sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && comp[i][j] == 0) {
                    area[id] = dfs(i, j, id, grid, comp);
                    ++id;
                }
            }
        }

        int maxArea = 0;

        // Step 2: try changing each 0 to 1 and calculate the area
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int total = 1; // we turn this 0 to 1
                    for (auto& d : directions) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && comp[ni][nj] != 0) {
                            int neighbor_id = comp[ni][nj];
                            if (seen.find(neighbor_id) == seen.end()) {
                                total += area[neighbor_id];
                                seen.insert(neighbor_id);
                            }
                        }
                    }
                    maxArea = max(maxArea, total);
                }
            }
        }

        // In case the grid is already full of 1s
        for (auto& [_, val] : area) {
            maxArea = max(maxArea, val);
        }

        return maxArea;
    }
};

// Main function for testing
int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1, 1},
        {0, 1}
    };

    vector<vector<int>> grid2 = {
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1}
    };

    cout << "Output 1: " << sol.MaxConnection(grid1) << endl; // Expected: 4
    cout << "Output 2: " << sol.MaxConnection(grid2) << endl; // Expected: 7

    return 0;
}
