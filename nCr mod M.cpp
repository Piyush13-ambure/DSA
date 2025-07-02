/*Given 2 integers n and r. You task is to calculate nCr%1000003.

Your Task:
You don't need to read or print anything. Your task is to complete the function nCr() which takes n and r as input parameter and returns nCr modulo 1000003.
 */

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000003;
vector<long long> fact(MOD), inv_fact(MOD);

// Fast exponentiation
long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

// Precompute factorials and inverse factorials modulo MOD
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MOD; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MOD - 1] = power(fact[MOD - 1], MOD - 2);
    for (int i = MOD - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

// Compute nCr % MOD when n, r < MOD
long long nCr_mod(long long n, long long r) {
    if (r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

class Solution {
public:
    int nCr(long long n, long long r) {
        precompute();
        long long result = 1;

        // Apply Lucas Theorem
        while (n > 0 || r > 0) {
            long long ni = n % MOD;
            long long ri = r % MOD;
            result = result * nCr_mod(ni, ri) % MOD;
            n /= MOD;
            r /= MOD;
        }

        return result;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    cout << sol.nCr(5, 2) << endl;       // Output: 10
    cout << sol.nCr(3, 2) << endl;       // Output: 3
    cout << sol.nCr(10000000000000LL, 3) << endl; // Large test
    return 0;
}
