/*Given a matrix mat[][] of dimension n * m where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

Examples:*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;  // Queue to store rotten oranges (i, j)
        int freshCount = 0;       // Count of fresh oranges

        // Step 1: Add all rotten oranges to queue and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // If no fresh oranges, return 0 (no time required)
        if (freshCount == 0) return 0;

        // Directions for up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;

        // Step 2: BFS traversal to rot adjacent fresh oranges
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int newX = x + dx, newY = y + dy;

                    // Check bounds and if the orange is fresh
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] == 1) {
                        mat[newX][newY] = 2; // Make it rotten
                        q.push({newX, newY});
                        freshCount--;
                        rotted = true;
                    }
                }
            }

            if (rotted) time++;  // Increase time only if at least one orange rotted
        }

        // If any fresh oranges are left, return -1
        return (freshCount == 0) ? time : -1;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    vector<vector<int>> mat1 = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    vector<vector<int>> mat2 = {{2, 2, 0, 1}};
    vector<vector<int>> mat3 = {{2, 2, 2}, {0, 2, 0}};

    cout << sol.orangesRotting(mat1) << endl; // Output: 1
    cout << sol.orangesRotting(mat2) << endl; // Output: -1
    cout << sol.orangesRotting(mat3) << endl; // Output: 0

    return 0;
}
