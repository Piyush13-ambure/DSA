/*Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].*/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int MAX_N = 1e6 + 1;
        vector<bool> isPrime(MAX_N, true);
        vector<int> primes;

        // Step 1: Sieve of Eratosthenes to find primes up to right
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        for (int i = 2; i * i < MAX_N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < MAX_N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Collect primes in the given range
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // Step 3: Find the closest pair
        if (primes.size() < 2) return {-1, -1};

        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    vector<int> result = sol.closestPrimes(10, 19);
    
    cout << "Closest primes: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
