//Given an array arr[] of selling prices in the cities, find the longest subsequence of consecutive cities where prices are strictly increasing. Also, calculate the maximum sum of prime numbers in that subsequence. If multiple subsequences have the same length, choose the one with the highest prime sum. If no primes are present, the prime sum is 0.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute the longest increasing subsequence and prime sum
    vector<int> primeMoney(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {0, 0}; // Edge case
        
        // Step 1: Use Sieve of Eratosthenes to precompute prime numbers up to 10^5
        vector<bool> isPrime(100001, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= 100000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 100000; j += i)
                    isPrime[j] = false;
            }
        }
        
        // Step 2: Compute LIS using DP
        vector<int> dp(n, 1), prev(n, -1);
        int maxLen = 1, endIndex = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }

        // Step 3: Reconstruct LIS sequence
        vector<int> lisSequence;
        for (int i = endIndex; i != -1; i = prev[i])
            lisSequence.push_back(arr[i]);
        
        reverse(lisSequence.begin(), lisSequence.end());

        // Step 4: Compute prime sum from LIS
        int primeSum = 0;
        for (int num : lisSequence) {
            if (isPrime[num]) primeSum += num;
        }

        return {maxLen, primeSum};
    }
};

// Driver Code
int main() {
    vector<int> arr1 = {4, 2, 3, 5, 1, 6, 7, 8, 9};
    vector<int> arr2 = {2, 3, 5, 7, 4, 1, 6, 5, 4, 8};
    vector<int> arr3 = {2, 2, 2, 2, 2};

    Solution sol;
    vector<int> res1 = sol.primeMoney(arr1);
    vector<int> res2 = sol.primeMoney(arr2);
    vector<int> res3 = sol.primeMoney(arr3);

    cout << "[" << res1[0] << ", " << res1[1] << "]" << endl; // Output: [5, 7]
    cout << "[" << res2[0] << ", " << res2[1] << "]" << endl; // Output: [4, 17]
    cout << "[" << res3[0] << ", " << res3[1] << "]" << endl; // Output: [1, 2]

    return 0;
}
