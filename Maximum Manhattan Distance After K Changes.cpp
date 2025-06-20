/*You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:

'N' : Move north by 1 unit.
'S' : Move south by 1 unit.
'E' : Move east by 1 unit.
'W' : Move west by 1 unit.
Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.

Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.

The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
 */
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <tuple>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        queue<tuple<int, int, int, int>> q; // index, x, y, k_used
        q.push({0, 0, 0, 0});
        int maxDist = 0;

        // To avoid visiting same state
        unordered_set<string> visited;

        while (!q.empty()) {
            auto [i, x, y, used] = q.front(); q.pop();
            maxDist = max(maxDist, abs(x) + abs(y));

            if (i == n) continue;

            // Generate a unique key for visited set
            string key = to_string(i) + "_" + to_string(x) + "_" + to_string(y) + "_" + to_string(used);
            if (visited.count(key)) continue;
            visited.insert(key);

            // Use original character
            int dx = 0, dy = 0;
            if (s[i] == 'N') dy = 1;
            else if (s[i] == 'S') dy = -1;
            else if (s[i] == 'E') dx = 1;
            else if (s[i] == 'W') dx = -1;

            q.push({i+1, x+dx, y+dy, used});

            // Try changing to other 3 directions
            if (used < k) {
                vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
                for (auto [ddx, ddy] : dirs) {
                    if (ddx == dx && ddy == dy) continue; // skip original move
                    q.push({i+1, x+ddx, y+ddy, used+1});
                }
            }
        }

        return maxDist;
    }
};

// ---------- Main function ----------
int main() {
    Solution sol;

    string s1 = "NWSE";
    int k1 = 1;
    cout << "Max Distance for 'NWSE', k=1: " << sol.maxDistance(s1, k1) << endl;

    string s2 = "NSWWEW";
    int k2 = 3;
    cout << "Max Distance for 'NSWWEW', k=3: " << sol.maxDistance(s2, k2) << endl;

    string s3 = "EEE";
    int k3 = 0;
    cout << "Max Distance for 'EEE', k=0: " << sol.maxDistance(s3, k3) << endl;

    return 0;
}
