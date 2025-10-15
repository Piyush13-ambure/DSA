/*You are given a 2d array grid[][] of size n×n (where n = 2k and k≥1), with all cells initialized to 0 except for one missing cell. Your task is to fill the entire grid using L-shaped tiles. An L-shaped tile covers 3 cells in a 2x2 grid, with one cell missing. You need to tile the entire grid using the L-shaped tiles, ensuring that the missing cell remains untouched.

Note: The missing cell is denoted by "-1" and you should fill the rest of the grid with integers such that each group of three identical numbers corresponds to one L-shaped tile.
If you fill the entire grid correctly the driver code will print true else it will print false.*/

class Solution {
  public:
    // Tile number to be filled
    int t = 0;

    // Function to place tiles in the sub-grids
    void place_tile(int x1, int y1, int x2, int y2, int x3, int y3,
                    vector<vector<int>> &grid) {
        t++;
        grid[x1][y1] = t;
        grid[x2][y2] = t;
        grid[x3][y3] = t;
    }

    // Recursive function to fill the grid
    void solve(int sz, int r, int c, vector<vector<int>> &grid) {
        // Base case: when the grid size is 2x2
        if (sz == 2) {
            t++;
            for (int i = 0; i < sz; i++)
                for (int j = 0; j < sz; j++)
                    if (grid[r + i][c + j] == 0)
                        grid[r + i][c + j] = t;
            return;
        }

        // To store the missing cell's coordinates
        int mr, mc;

        // Find the missing cell within the current sub-grid
        for (int i = r; i < r + sz; i++)
            for (int j = c; j < c + sz; j++)
                if (grid[i][j] != 0)
                    mr = i, mc = j;

        // Place tiles based on the quadrant where the missing cell is located
        // First quadrant
        if (mr < r + sz / 2 && mc < c + sz / 2)
            place_tile(r + sz / 2, c + sz / 2 - 1, r + sz / 2, c + sz / 2,
                       r + sz / 2 - 1, c + sz / 2, grid);
        // Second quadrant
        else if (mr >= r + sz / 2 && mc < c + sz / 2)
            place_tile(r + sz / 2 - 1, c + sz / 2, r + sz / 2, c + sz / 2,
                       r + sz / 2 - 1, c + sz / 2 - 1, grid);
        // Third quadrant
        else if (mr < r + sz / 2 && mc >= c + sz / 2)
            place_tile(r + sz / 2, c + sz / 2 - 1, r + sz / 2, c + sz / 2,
                       r + sz / 2 - 1, c + sz / 2 - 1, grid);
        // Fourth quadrant
        else
            place_tile(r + sz / 2 - 1, c + sz / 2, r + sz / 2, c + sz / 2 - 1,
                       r + sz / 2 - 1, c + sz / 2 - 1, grid);

        // Recursively solve for the 4 sub-grids
        // Top-right
        solve(sz / 2, r, c + sz / 2, grid);
        // Top-left
        solve(sz / 2, r, c, grid);
        // Bottom-left
        solve(sz / 2, r + sz / 2, c, grid);
        // Bottom-right
        solve(sz / 2, r + sz / 2, c + sz / 2, grid);
    }

    void fillTile(int n, vector<vector<int>> &grid) { solve(n, 0, 0, grid); }
};
