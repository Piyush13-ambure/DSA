/*There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls on the occasion of New Year. Alexa can color each wall with one of the K colors. The cost associated with coloring each wall with a particular color is represented by a 2D costs array of size N * K. For example, costs[0][0] is the cost of coloring wall 0 with color 0; costs[1][2] is the cost of coloring wall 1 with color 2, and so on... Find the minimum cost to color all the walls such that no two adjacent walls have the same color.

Note: If you are not able to paint all the walls, then you should return -1
Your Task:

Your task is to complete the function minCost() which takes a 2D integer matrix costs as the only argument and returns an integer, representing the minimum cost to paint all the walls. If you are not able to paint all the walls, then you should return -1.*/




#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int N = costs.size();
        if (N == 0) return 0;
        int K = costs[0].size();

        if (K == 0 || (K == 1 && N > 1)) return -1;

        vector<vector<int>> dp(N, vector<int>(K, 0));

        // Initialize the first wall
        for (int j = 0; j < K; ++j) {
            dp[0][j] = costs[0][j];
        }

        for (int i = 1; i < N; ++i) {
            // Find the smallest and second smallest in dp[i-1]
            int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;
            for (int j = 0; j < K; ++j) {
                if (dp[i - 1][j] < min1) {
                    min2 = min1;
                    min1 = dp[i - 1][j];
                    idx1 = j;
                } else if (dp[i - 1][j] < min2) {
                    min2 = dp[i - 1][j];
                }
            }

            for (int j = 0; j < K; ++j) {
                if (j == idx1)
                    dp[i][j] = costs[i][j] + min2;
                else
                    dp[i][j] = costs[i][j] + min1;
            }
        }

        // Final answer is the minimum in the last row
        int result = INT_MAX;
        for (int j = 0; j < K; ++j) {
            result = min(result, dp[N - 1][j]);
        }

        return result;
    }
};

// Example driver
int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> costs1 = {{1, 5, 7},
                                  {5, 8, 4},
                                  {3, 2, 9},
                                  {1, 2, 4}};
    cout << "Example 1 Output: " << sol.minCost(costs1) << endl;

    // Example 2
    vector<vector<int>> costs2 = {{5},
                                  {4},
                                  {9},
                                  {2},
                                  {1}};
    cout << "Example 2 Output: " << sol.minCost(costs2) << endl;

    return 0;
}
