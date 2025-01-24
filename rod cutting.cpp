//Given a rod of length n(size of price) inches and an array of prices, price. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<int> dp(n + 1, 0); // dp[i] stores the maximum value for a rod of length i

        // Build the dp array iteratively
        for (int i = 1; i <= n; i++) { // i is the rod length being considered
            for (int j = 1; j <= i; j++) { // j is the cut length
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }

        return dp[n];
    }
};

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> price(n);
    cout << "Enter the prices for rod pieces of length 1 to " << n << ": ";
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    Solution sol;
    int result = sol.cutRod(price);
    cout << "The maximum obtainable value is: " << result << "\n";

    return 0;
}
