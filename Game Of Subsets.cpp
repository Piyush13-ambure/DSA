/*Elena is the topper of the class. Once her teacher asked her a problem. He gave Elena an array of integers of length n. He calls a subset of array arr good if its product can be represented as a product of one or more distinct prime numbers. He asked her to find the number of different good subsets in arr modulo 109 + 7.

As a good friend of Elena help her to solve the problem.
Your Task:
The task is to complete the function goodSubsets() which takes an integer n and an array arr as the input parameters and should return the number of different good subsets.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int goodSubsets(vector<int> &arr, int n) {
        const int MOD = 1e9 + 7;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        unordered_map<int, int> count;
        for (int num : arr) count[num]++;

        // Precompute masks for square-free numbers up to 30
        unordered_map<int, int> numToMask;
        for (int i = 2; i <= 30; ++i) {
            int mask = 0;
            int x = i;
            bool isValid = true;
            for (int j = 0; j < primes.size(); ++j) {
                int p = primes[j];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                if (cnt > 1) {
                    isValid = false;
                    break;
                }
                if (cnt == 1) mask |= (1 << j);
            }
            if (isValid) numToMask[i] = mask;
        }

        // dp[mask] = number of ways to form subsets with this mask
        vector<int> dp(1 << 10);
        dp[0] = 1;

        for (auto &[num, freq] : count) {
            if (num == 1 || numToMask.find(num) == numToMask.end()) continue;
            int currMask = numToMask[num];
            for (int mask = (1 << 10) - 1; mask >= 0; --mask) {
                if ((mask & currMask) == 0) {
                    dp[mask | currMask] = (dp[mask | currMask] + 1LL * dp[mask] * freq) % MOD;
                }
            }
        }

        // Sum all dp[mask] except dp[0] (empty subset)
        int result = 0;
        for (int mask = 1; mask < (1 << 10); ++mask) {
            result = (result + dp[mask]) % MOD;
        }

        // Multiply by 2^count[1] to include 1's
        int ones = count[1];
        if (ones > 0) {
            long long power = 1;
            for (int i = 0; i < ones; ++i) {
                power = (power * 2) % MOD;
            }
            result = (1LL * result * power) % MOD;
        }

        return result;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    int n1 = 4;
    vector<int> arr1 = {1, 2, 3, 4};
    cout << "Output 1: " << sol.goodSubsets(arr1, n1) << endl;

    int n2 = 3;
    vector<int> arr2 = {2, 2, 3};
    cout << "Output 2: " << sol.goodSubsets(arr2, n2) << endl;

    return 0;
}


