/*You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;

    // Helper to generate all valid column colorings of height m
    void generateStates(int m, int pos, vector<int>& curr, vector<vector<int>>& states) {
        if (pos == m) {
            states.push_back(curr);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (pos == 0 || curr[pos - 1] != color) {
                curr[pos] = color;
                generateStates(m, pos + 1, curr, states);
            }
        }
    }

public:
    int colorTheGrid(int m, int n) {
        vector<vector<int>> states;
        vector<int> curr(m);
        generateStates(m, 0, curr, states);

        int stateCount = states.size();
        vector<vector<int>> transitions(stateCount);

        // Precompute valid transitions
        for (int i = 0; i < stateCount; ++i) {
            for (int j = 0; j < stateCount; ++j) {
                bool valid = true;
                for (int k = 0; k < m; ++k) {
                    if (states[i][k] == states[j][k]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) transitions[i].push_back(j);
            }
        }

        // DP: dp[i][j] = number of ways to fill up to column j with i-th state
        vector<int> dp(stateCount, 1);

        for (int col = 1; col < n; ++col) {
            vector<int> new_dp(stateCount, 0);
            for (int i = 0; i < stateCount; ++i) {
                for (int j : transitions[i]) {
                    new_dp[j] = (new_dp[j] + dp[i]) % MOD;
                }
            }
            dp = new_dp;
        }

        int result = 0;
        for (int count : dp) result = (result + count) % MOD;
        return result;
    }
};

// ---------- Sample Main Function ----------
int main() {
    Solution sol;

    // Test Case 1
    cout << "Output (m=1, n=1): " << sol.colorTheGrid(1, 1) << endl;

    // Test Case 2
    cout << "Output (m=1, n=2): " << sol.colorTheGrid(1, 2) << endl;

    // Test Case 3
    cout << "Output (m=5, n=5): " << sol.colorTheGrid(5, 5) << endl;

    return 0;
}
