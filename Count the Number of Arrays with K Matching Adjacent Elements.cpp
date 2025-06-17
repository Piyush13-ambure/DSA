/*You are given three integers n, m, k. A good array arr of size n is defined as follows:

Each element in arr is in the inclusive range [1, m].
Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
Return the number of good arrays that can be formed.

Since the answer may be very large, return it modulo 109 + 7.

*/


#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

long long fact[MAX], invFact[MAX];

// Modular exponentiation
long long modPow(long long base, long long exp, int mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invFact[i] = modPow(fact[i], MOD - 2, MOD);
    }
}

// Compute C(n, k) % MOD
long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        precompute(); // Precompute factorials

        long long ways = comb(n - 1, k);                  // Choose k positions to be equal
        ways = ways * m % MOD;                            // Choose first value
        ways = ways * modPow(m - 1, n - 1 - k, MOD) % MOD; // For rest, choose different values
        return ways;
    }
};

int main() {
    Solution sol;

    cout << "Example 1: " << sol.countGoodArrays(3, 2, 1) << endl; // Output: 4
    cout << "Example 2: " << sol.countGoodArrays(4, 2, 2) << endl; // Output: 6
    cout << "Example 3: " << sol.countGoodArrays(5, 2, 0) << endl; // Output: 2

    return 0;
}
