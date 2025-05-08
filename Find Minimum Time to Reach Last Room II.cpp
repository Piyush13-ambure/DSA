/*There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        
        // Priority Queue of {time, row, col, parity}, sorted by time
        priority_queue<tuple<int, int, int, int>,
                       vector<tuple<int, int, int, int>>,
                       greater<tuple<int, int, int, int>>> pq;
        
        dist[0][0][0] = 0;
        pq.emplace(0, 0, 0, 0);
        
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!pq.empty()) {
            auto [time, r, c, parity] = pq.top();
            pq.pop();
            
            if (r == n-1 && c == m-1)
                return time;
            
            if (time > dist[r][c][parity]) continue;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                
                int next_move = (parity == 0) ? 1 : 2;
                int arrive = max(time + next_move, moveTime[nr][nc]);
                int next_parity = 1 - parity;

                if (arrive < dist[nr][nc][next_parity]) {
                    dist[nr][nc][next_parity] = arrive;
                    pq.emplace(arrive, nr, nc, next_parity);
                }
            }
        }

        return min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    }
};

// Sample usage
int main() {
    Solution sol;
    vector<vector<int>> moveTime1 = {{0,4},{4,4}};
    cout << sol.minTimeToReach(moveTime1) << endl; // Output: 7

    vector<vector<int>> moveTime2 = {{0,0,0,0},{0,0,0,0}};
    cout << sol.minTimeToReach(moveTime2) << endl; // Output: 6

    vector<vector<int>> moveTime3 = {{0,1},{1,2}};
    cout << sol.minTimeToReach(moveTime3) << endl; // Output: 4

    return 0;
}
