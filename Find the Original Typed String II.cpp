/*
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.

Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.

Since the answer may be very large, return it modulo 109 + 7.


*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int possibleStringCount(string word, int k) {
        vector<int> groupLens;
        int n = word.length(), i = 0;

        // Step 1: Count lengths of consecutive identical characters
        while (i < n) {
            char curr = word[i];
            int count = 0;
            while (i < n && word[i] == curr) {
                ++count;
                ++i;
            }
            groupLens.push_back(count);
        }

        int m = groupLens.size();
        int maxSum = 0;
        for (int len : groupLens) maxSum += len;

        // Step 2: DP[i][j] = number of ways using first i groups to get sum j
        vector<int> dp(maxSum + 1);
        dp[0] = 1;

        for (int idx = 0; idx < m; ++idx) {
            int len = groupLens[idx];
            vector<int> new_dp(maxSum + 1, 0);

            // Prefix sum for range updates
            vector<int> prefix(maxSum + 2, 0);
            for (int s = 0; s <= maxSum; ++s) {
                if (dp[s] > 0) {
                    prefix[s + 1] = (prefix[s + 1] + dp[s]) % MOD;
                    if (s + len + 1 <= maxSum)
                        prefix[s + len + 1] = (prefix[s + len + 1] - dp[s] + MOD) % MOD;
                }
            }

            // Build new_dp from prefix sum
            int curr = 0;
            for (int s = 0; s <= maxSum; ++s) {
                curr = (curr + prefix[s + 1]) % MOD;
                new_dp[s] = curr;
            }

            dp = new_dp;
        }

        // Step 3: Sum over all valid lengths ≥ k
        int ans = 0;
        for (int i = k; i <= maxSum; ++i) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};

// Main function to run sample cases
int main() {
    Solution sol;
    cout << sol.possibleStringCount("aabbccdd", 7) << endl;  // Output: 5
    cout << sol.possibleStringCount("aabbccdd", 8) << endl;  // Output: 1
    cout << sol.possibleStringCount("aaabbb", 3) << endl;    // Output: 8
    return 0;
}
