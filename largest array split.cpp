//Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(int arr[], int N, int K) {
        // Helper function to check if a maximum sum is valid
        auto isValid = [&](int maxSum) -> bool {
            int subarrayCount = 1; // At least one subarray
            int currentSum = 0;

            for (int i = 0; i < N; i++) {
                if (currentSum + arr[i] > maxSum) {
                    subarrayCount++; // Start a new subarray
                    currentSum = arr[i]; // Current element starts the new subarray
                    if (subarrayCount > K) return false; // Too many subarrays
                } else {
                    currentSum += arr[i];
                }
            }

            return true;
        };

        // Binary search on the result
        int low = *max_element(arr, arr + N); // Maximum element
        int high = accumulate(arr, arr + N, 0); // Sum of all elements
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(mid)) {
                result = mid; // Update result if valid
                high = mid - 1; // Try to minimize further
            } else {
                low = mid + 1; // Increase the allowable maximum sum
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    int arr[] = {7, 2, 5, 10, 8};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    cout << "The minimum possible maximum subarray sum is: " << solution.splitArray(arr, N, K) << endl;

    return 0;
}
