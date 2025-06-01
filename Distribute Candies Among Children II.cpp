/*You are given two positive integers n and limit.

Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

*/

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 3e6 + 10;

long long fact[MAX], invFact[MAX];

// Fast exponentiation
long long modPow(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invFact[i] = modPow(fact[i], MOD - 2, MOD);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long total = 0;
        for (int i = 0; i <= 3; ++i) {
            int sign = (i % 2 == 0) ? 1 : -1;
            long long comb = nCr(3, i);
            int remaining = n - i * (limit + 1);
            if (remaining < 0) continue;
            total = (total + sign * comb % MOD * nCr(remaining + 2, 2) % MOD + MOD) % MOD;
        }
        return total;
    }
};

int main() {
    precompute();
    Solution sol;
    int n, limit;
    cout << "Enter n and limit: ";
    cin >> n >> limit;

    cout << "Total number of ways: " << sol.distributeCandies(n, limit) << endl;
    return 0;
}
