/*Given two positive integers n and x.

Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

Since the result can be very large, return it modulo 109 + 7.

For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

 */

#include <vector>
using namespace std;
static const int MOD = 1'000'000'007;

class Solution {
public:
    int numberOfWays(int n, int x) {
        // collect powers i^x <= n
        vector<int> powers;
        for (int i = 1; ; ++i) {
            long long p = 1;
            for (int k = 0; k < x; ++k) p *= i;
            if (p > n) break;
            powers.push_back((int)p);
        }

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int p : powers) {
            for (int s = n; s >= p; --s) {
                dp[s] = (dp[s] + dp[s - p]) % MOD;
            }
        }
        return (int)dp[n];
    }
};
