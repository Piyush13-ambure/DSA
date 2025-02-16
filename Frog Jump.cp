//Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0; // If there's only one stair, no cost is needed.
        
        vector<int> dp(n, 0);
        dp[0] = 0; // No cost at the first stair
        dp[1] = abs(height[1] - height[0]); // Cost to reach the second stair
        
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1] + abs(height[i] - height[i - 1]),
                        dp[i - 2] + abs(height[i] - height[i - 2]));
        }
        
        return dp[n - 1]; // Minimum cost to reach the last stair
    }
};

int main() {
    vector<int> heights1 = {20, 30, 40, 20};
    vector<int> heights2 = {30, 20, 50, 10, 40};

    Solution solution;
    cout << "Output: " << solution.minCost(heights1) << endl; // Expected: 20
    cout << "Output: " << solution.minCost(heights2) << endl; // Expected: 30

    return 0;
}
