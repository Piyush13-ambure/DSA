/*
You are given two integers n and maxValue, which are used to describe an ideal array.

A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:

Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.

 */
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 10005;

class Solution {
public:
    vector<int> fac, inv;

    // Fast exponentiation
    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2) res = res * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return res;
    }

    // Precompute factorials and inverse factorials
    void precomputeFactorials(int n) {
        fac.resize(n + 1);
        inv.resize(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % MOD;
        for (int i = 0; i <= n; ++i) inv[i] = power(fac[i], MOD - 2);
    }

    int comb(int n, int r) {
        if (r > n) return 0;
        return 1LL * fac[n] * inv[r] % MOD * inv[n - r] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        precomputeFactorials(n + 100); // Enough for combinations

        vector<vector<int>> dp(16, vector<int>(maxValue + 1, 0));

        // dp[k][x] = number of increasing ideal arrays of length k ending in x
        for (int i = 1; i <= maxValue; ++i) dp[1][i] = 1;

        for (int len = 2; len <= 15; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int j = 2 * i; j <= maxValue; j += i) {
                    dp[len][j] = (dp[len][j] + dp[len - 1][i]) % MOD;
                }
            }
        }

        int result = 0;
        for (int len = 1; len <= 15; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                if (dp[len][i]) {
                    result = (result + 1LL * dp[len][i] * comb(n - 1, len - 1) % MOD) % MOD;
                }
            }
        }
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.idealArrays(2, 5) << endl; // Output: 10
    cout << sol.idealArrays(5, 3) << endl; // Output: 11
    return 0;
}

