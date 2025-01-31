//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.Return the size of the largest island in grid after applying this operation.An island is a 4-directionally connected group of 1s.


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Helper function to perform DFS and find island size
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1)
            return 0;

        grid[i][j] = index; // Mark the cell with island index
        int size = 1;

        for (auto& d : directions)
            size += dfs(grid, i + d[0], j + d[1], index);

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize; // Store island sizes
        int index = 2, maxIsland = 0;

        // Step 1: Find all islands and assign unique indices
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, index);
                    islandSize[index] = size;
                    maxIsland = max(maxIsland, size);
                    index++;
                }
            }
        }

        // Step 2: Try converting each 0 into 1 and calculate the new island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seenIslands;
                    int newSize = 1; // Count this new 1

                    for (auto& d : directions) {
                        int ni = i + d[0], nj = j + d[1];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            int islandIndex = grid[ni][nj];
                            if (seenIslands.find(islandIndex) == seenIslands.end()) {
                                newSize += islandSize[islandIndex];
                                seenIslands.insert(islandIndex);
                            }
                        }
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        // Edge case: If the grid is already all 1s
        return maxIsland == 0 ? n * n : maxIsland;
    }
};

// Example Usage
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    cout << sol.largestIsland(grid) << endl;  // Output: 3

    vector<vector<int>> grid2 = {{1, 1}, {1, 0}};
    cout << sol.largestIsland(grid2) << endl;  // Output: 4

    return 0;
}
