/*Given two integers N and K, the task is to count the number of ways to divide N into groups of positive integers. Such that each group shall have K elements and their sum is N. Also the number of elements in the groups follows a non-decreasing order (i.e. group[i] <= group[i+1]). Find the number of such groups
Your Task:
Complete the function countWaystoDivide() which takes the integers N and K as the input parameters, and returns the number of ways to divide the sum N into K groups.


*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countWaystoDivide(int N, int K) {
        // dp[pos][sum][prev] - ways to divide 'sum' into 'pos' parts with minimum starting value 'prev'
        vector<vector<vector<int>>> dp(K + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, -1)));
        return count(N, K, 1, dp);
    }

private:
    int count(int sum, int k, int prev, vector<vector<vector<int>>>& dp) {
        if (k == 0) return sum == 0 ? 1 : 0;
        if (sum < 0) return 0;
        if (dp[k][sum][prev] != -1) return dp[k][sum][prev];

        int ways = 0;
        for (int i = prev; i <= sum; ++i) {
            ways += count(sum - i, k - 1, i, dp);
        }

        return dp[k][sum][prev] = ways;
    }
};

// Main function for testing
int main() {
    Solution sol;

    int N1 = 8, K1 = 4;
    cout << "Input: N = " << N1 << ", K = " << K1 << "\n";
    cout << "Output: " << sol.countWaystoDivide(N1, K1) << "\n"; // Expected: 5

    int N2 = 4, K2 = 3;
    cout << "\nInput: N = " << N2 << ", K = " << K2 << "\n";
    cout << "Output: " << sol.countWaystoDivide(N2, K2) << "\n"; // Expected: 1

    return 0;
}
