/*Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.*/
class Solution {
  public:

    // Directions: Down, Left, Right, Up
    string dir = "DLRU";
    int dr[4] = {1, 0, 0, -1};
    int dc[4] = {0, -1, 1, 0};

    // Check if a cell is valid (inside the maze and open)
    bool isValid(int r, int c, int n, vector<vector<int>>& maze) {
        return r >= 0 && c >= 0 && r < n && c < n && maze[r][c];
    }

    // Function to find all valid paths
    void findPath(int r, int c, vector<vector<int>>& maze, string& path,
                  vector<string>& res) {
        int n = maze.size();

        // If destination is reached, store the path
        if (r == n - 1 && c == n - 1) {
            res.push_back(path);
            return;
        }

        // Mark current cell as blocked
        maze[r][c] = 0;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (isValid(nr, nc, n, maze)) {
                path.push_back(dir[i]);

                // Recurse to next cell
                findPath(nr, nc, maze, path, res);

                // Backtrack
                path.pop_back();
            }
        }

        // Unmark current cell
        maze[r][c] = 1;
    }

    // Function to find all paths and return them
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> result;
        int n = maze.size();
        string path = "";

        if (maze[0][0] != 0 && maze[n - 1][n - 1] != 0) {

            // Start from (0,0)
            findPath(0, 0, maze, path, result);
        }

        sort(result.begin(), result.end());
        return result;
    }
};
