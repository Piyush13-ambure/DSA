/*Given a number n, find out if n can be expressed as a+b, where both a and b are prime numbers. If such a pair exists, return the values of a and b, otherwise return [-1,-1] as an array of size 2.
Note: If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then  [a, b] is considered as our answer.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getPrimes(int n) {
        if (n < 2) return {-1, -1};

        // Step 1: Use Sieve of Eratosthenes to find all prime numbers up to n
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        // Step 2: Find the smallest pair (a, b) such that a + b = n
        for (int a = 2; a <= n / 2; a++) {
            int b = n - a;
            if (is_prime[a] && is_prime[b]) {
                return {a, b};
            }
        }

        return {-1, -1}; // No valid pair found
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    vector<int> result = sol.getPrimes(n);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}
