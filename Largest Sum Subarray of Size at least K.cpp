//Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k) {
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = a[0];

        // Compute prefix sum array
        for (long long i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + a[i];

        long long maxSum = LLONG_MIN;
        long long minPrefixSum = 0;

        // Sliding window approach
        for (long long i = k - 1; i < n; i++) {
            long long currSum = prefixSum[i] - minPrefixSum;
            maxSum = max(maxSum, currSum);

            if (i - k + 1 >= 0)
                minPrefixSum = min(minPrefixSum, prefixSum[i - k + 1]);
        }

        return maxSum;
    }
};


int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

