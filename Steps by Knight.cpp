/*Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Possible moves of the knight
    vector<pair<int, int>> directions = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        // Convert 1-based index to 0-based index
        int startX = KnightPos[0] - 1, startY = KnightPos[1] - 1;
        int targetX = TargetPos[0] - 1, targetY = TargetPos[1] - 1;

        // If the knight is already at the target position
        if (startX == targetX && startY == targetY) return 0;

        // BFS initialization
        queue<pair<int, int>> q;
        q.push({startX, startY});
        
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        visited[startX][startY] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            steps++;

            // Process all nodes at the current depth level
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                // Explore all 8 possible knight moves
                for (auto [dx, dy] : directions) {
                    int newX = x + dx, newY = y + dy;

                    // Check if the new position is within bounds and not visited
                    if (newX >= 0 && newX < N && newY >= 0 && newY < N && !visited[newX][newY]) {
                        // If we reached the target
                        if (newX == targetX && newY == targetY) return steps;

                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return -1; // Should never reach here since the knight can always reach any position
    }
};

// Driver Code
int main() {
    Solution sol;
    int N = 8;
    vector<int> KnightPos = {1, 1}, TargetPos = {8, 8};
    cout << "Minimum steps: " << sol.minStepToReachTarget(KnightPos, TargetPos, N) << endl;
    return 0;
}
