/*You have got a maze, which is a n*n Grid. Every cell of the maze contains these numbers 1, 2 or 3. 
If it contains 1 : means we can go Right from that cell only.
If it contains 2 : means we can go Down from that cell only.
If it contains 3 : means we can go Right and Down to both paths from that cell.
We cant go out of the maze at any time.
Initially, You are on the Top Left Corner of The maze(Entry). And, You need to go to the Bottom Right Corner of the Maze(Exit).
You need to find the total number of paths from Entry to Exit Point.
There may be many paths but you need to select that path which contains the maximum number of Adventure.
The Adventure on a path is calculated by taking the sum of all the cell values thatlies in the path.


Your Task:
You don't need to read or print anything. Your task is to complete the function FindWays() which takes matrix as input parameter and returns a list containg total number of ways to reach at (n, n) modulo 109 + 7 and maximum number of Adventure.
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> FindWays(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp_ways(n, vector<int>(n, 0));
        vector<vector<int>> dp_adventure(n, vector<int>(n, 0));

        dp_ways[0][0] = 1;
        dp_adventure[0][0] = matrix[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int maxAdventure = -1;
                int ways = 0;

                // From top (Down move)
                if (i > 0 && (matrix[i - 1][j] == 2 || matrix[i - 1][j] == 3)) {
                    if (dp_adventure[i - 1][j] > maxAdventure) {
                        maxAdventure = dp_adventure[i - 1][j];
                        ways = dp_ways[i - 1][j];
                    } else if (dp_adventure[i - 1][j] == maxAdventure) {
                        ways = (ways + dp_ways[i - 1][j]) % MOD;
                    }
                }

                // From left (Right move)
                if (j > 0 && (matrix[i][j - 1] == 1 || matrix[i][j - 1] == 3)) {
                    if (dp_adventure[i][j - 1] > maxAdventure) {
                        maxAdventure = dp_adventure[i][j - 1];
                        ways = dp_ways[i][j - 1];
                    } else if (dp_adventure[i][j - 1] == maxAdventure) {
                        ways = (ways + dp_ways[i][j - 1]) % MOD;
                    }
                }

                if (ways > 0) {
                    dp_ways[i][j] = ways;
                    dp_adventure[i][j] = maxAdventure + matrix[i][j];
                }
            }
        }

        int totalWays = dp_ways[n - 1][n - 1] % MOD;
        int maxAdventure = dp_adventure[n - 1][n - 1];

        return {totalWays, maxAdventure};
    }
};

// Example main function to test the solution
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 3, 2, 1},
        {3, 2, 2, 1, 2},
        {1, 3, 3, 1, 3},
        {1, 2, 3, 1, 2},
        {1, 1, 1, 3, 1}
    };

    vector<int> result = sol.FindWays(matrix);
    cout << "{" << result[0] << ", " << result[1] << "}" << endl;

    return 0;
}
