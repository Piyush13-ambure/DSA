/*Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i - 1] <= w) {
                    dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }
};

int main() {
    Solution sol;
    int W = 5;
    vector<int> val = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 2, 3};
    
    cout << "Maximum value in Knapsack: " << sol.knapsack(W, val, wt) << endl;
    return 0;
}
