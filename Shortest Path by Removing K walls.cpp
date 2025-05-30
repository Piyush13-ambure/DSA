/*Given a 2-D binary matrix of size n*m, where 0 represents an empty space while 1 represents a wall you cannot walk through. You are also given an integer k.
You can walk up, down, left, or right. Given that you can remove up to k walls, return the minimum number of steps to walk from the top left corner (0, 0) to the bottom right corner (n-1, m-1).
Note: If there is no way to walk from the top left corner to the bottom right corner, return -1.
  Your Task:
The task is to complete the function shotestPath() which takes three integers n, m, and k and also a matrix of size n*m as input and returns the minimum number of steps to walk from the top left corner to the bottom right corner.*/


#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        if (mat[0][0] == 1 || mat[n-1][m-1] == 1) return -1;

        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
        queue<tuple<int, int, int, int>> q; // (x, y, steps, walls_removed)

        q.push({0, 0, 0, 0});
        visited[0][0][0] = true;

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [x, y, steps, walls] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1)
                return steps;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newWalls = walls + mat[nx][ny];

                    if (newWalls <= k && !visited[nx][ny][newWalls]) {
                        visited[nx][ny][newWalls] = true;
                        q.push({nx, ny, steps + 1, newWalls});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    int n1 = 3, m1 = 3, k1 = 1;
    vector<vector<int>> mat1 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}
    };
    cout << "Output 1: " << sol.shotestPath(mat1, n1, m1, k1) << endl;

    int n2 = 2, m2 = 2, k2 = 0;
    vector<vector<int>> mat2 = {
        {0, 1},
        {1, 0}
    };
    cout << "Output 2: " << sol.shotestPath(mat2, n2, m2, k2) << endl;

    return 0;
}
