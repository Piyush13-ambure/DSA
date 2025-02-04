//Given an array A[] of N integers. The task is to partition the array into four non-empty contiguous subarrays P, Q, R, and S such that each element of the array A[] should be present in any subarray.
//Let W, X, Y, and Z be the sum of the elements in P, Q, R, and S respectively.
//Find the smallest absolute difference between the maximum and the minimum among W, X, Y, and Z.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minDifference(int N, vector<int> &A) {
        vector<long long> prefixSum(N, 0);
        prefixSum[0] = A[0];

        // Compute prefix sum array
        for (int i = 1; i < N; i++) {
            prefixSum[i] = prefixSum[i - 1] + A[i];
        }

        long long minDiff = LLONG_MAX;

        // Try to find i, j, k to partition the array
        for (int i = 0; i < N - 3; i++) {
            long long W = prefixSum[i];

            // Find j using binary search
            int low = i + 1, high = N - 2;
            while (low < high) {
                int mid = low + (high - low) / 2;
                long long leftSum = prefixSum[mid] - W;
                long long rightSum = prefixSum[N - 1] - prefixSum[mid];

                if (leftSum < rightSum) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }

            int j = low;
            long long X = prefixSum[j] - W;

            // Find k using binary search
            low = j + 1, high = N - 1;
            while (low < high) {
                int mid = low + (high - low) / 2;
                long long leftSum = prefixSum[mid] - prefixSum[j];
                long long rightSum = prefixSum[N - 1] - prefixSum[mid];

                if (leftSum < rightSum) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }

            int k = low;
            long long Y = prefixSum[k] - prefixSum[j];
            long long Z = prefixSum[N - 1] - prefixSum[k];

            long long maxSum = max({W, X, Y, Z});
            long long minSum = min({W, X, Y, Z});
            minDiff = min(minDiff, maxSum - minSum);
        }

        return minDiff;
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    Solution obj;
    cout << obj.minDifference(N, A) << endl;

    return 0;
}
