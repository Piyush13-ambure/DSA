/*There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        time[0][0] = 0;
        pq.push({0, 0, 0});  // time, row, col

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!pq.empty()) {
            auto [curTime, i, j] = pq.top();
            pq.pop();

            if (i == n - 1 && j == m - 1) return curTime;

            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int nextTime = curTime + 1;
                    if (nextTime < moveTime[ni][nj]) {
                        // Wait until moveTime[ni][nj], but ensure we step at an even second (because you can only move in 1s)
                        int wait = moveTime[ni][nj] - nextTime;
                        if (wait % 2 == 1) wait++;
                        nextTime += wait;
                    }
                    if (nextTime < time[ni][nj]) {
                        time[ni][nj] = nextTime;
                        pq.push({nextTime, ni, nj});
                    }
                }
            }
        }

        return -1; // unreachable
    }
};

int main() {
    Solution sol;

    vector<vector<int>> moveTime1 = {{0,4},{4,4}};
    cout << "Example 1 Output: " << sol.minTimeToReach(moveTime1) << endl;

    vector<vector<int>> moveTime2 = {{0,0,0},{0,0,0}};
    cout << "Example 2 Output: " << sol.minTimeToReach(moveTime2) << endl;

    vector<vector<int>> moveTime3 = {{0,1},{1,2}};
    cout << "Example 3 Output: " << sol.minTimeToReach(moveTime3) << endl;

    return 0;
}
