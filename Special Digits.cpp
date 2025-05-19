/*You are given 5 integers - N,A,B,C,D.
Let us say all the integers of length N, having only A or B in their decimal representation are good integers. Also, among all the good integers, all those integers whose sum of digits should contains either C or D or both on it, are best integers.
Find the number of best integers of length N. Since the number of best integers can be huge, print it modulo 109+7.
Your Task:
The task is to complete the function solve() which takes five integers N,A,B,C and D as input parameters and returns the number of best integers modulo 109+7.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Precompute factorials and inverse factorials
    void precomputeFactorials(int n, vector<long long>& fact, vector<long long>& inv_fact) {
        fact[0] = inv_fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 1; --i)
            inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }

    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    long long modInverse(long long a) {
        return modPow(a, MOD - 2);
    }

    bool isValid(int sum, int C, int D) {
        while (sum > 0) {
            int digit = sum % 10;
            if (digit == C || digit == D) return true;
            sum /= 10;
        }
        return false;
    }

    int bestNumbers(int N, int A, int B, int C, int D) {
        vector<long long> fact(N + 1), inv_fact(N + 1);
        precomputeFactorials(N, fact, inv_fact);

        long long ans = 0;
        for (int k = 0; k <= N; ++k) {
            int sum = k * A + (N - k) * B;
            if (isValid(sum, C, D)) {
                long long comb = (fact[N] * inv_fact[k]) % MOD;
                comb = (comb * inv_fact[N - k]) % MOD;
                ans = (ans + comb) % MOD;
            }
        }

        return (int)ans;
    }
};

// Main function
int main() {
    Solution sol;
    int N, A, B, C, D;
    
    // Example input
    N = 2, A = 1, B = 2, C = 3, D = 5;
    cout << sol.bestNumbers(N, A, B, C, D) << endl;  // Output: 2

    N = 1, A = 1, B = 1, C = 2, D = 3;
    cout << sol.bestNumbers(N, A, B, C, D) << endl;  // Output: 0

    N = 4, A = 6, B = 7, C = 5, D = 3;
    cout << sol.bestNumbers(N, A, B, C, D) << endl;  // Output: 4

    return 0;
}


