//Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        int fullMask = (1 << n) - 1; // All cities visited
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));

        // Base case: Cost of visiting each city directly from city 0
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = cost[0][i];
        }

        // Iterate through all subsets of cities
        for (int mask = 1; mask <= fullMask; mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) { // If city `i` is in the current subset
                    for (int j = 0; j < n; j++) {
                        if (mask & (1 << j) && i != j) { // If city `j` is also in the subset
                            dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + cost[j][i]);
                        }
                    }
                }
            }
        }

        // Calculate the minimum cost to complete the tour
        int minCost = INT_MAX;
        for (int i = 1; i < n; i++) {
            minCost = min(minCost, dp[fullMask][i] + cost[i][0]);
        }
        return minCost;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum cost to complete the tour: " << solution.tsp(cost) << endl;
    return 0;
}
