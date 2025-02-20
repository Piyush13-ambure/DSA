//Given an array arr[] of distinct integers of size n and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Step 1: Sort the array
        sort(arr, arr + n);

        long long count = 0;

        // Step 2: Fix the first element and use two-pointer approach for the rest
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                long long currentSum = arr[i] + arr[left] + arr[right];

                if (currentSum < sum) {
                    // All elements between left and right form valid triplets
                    count += (right - left);
                    left++;  // Move left pointer to find more valid pairs
                } else {
                    right--; // Move right pointer to decrease sum
                }
            }
        }
        
        return count;
    }
};

// Driver code
int main() {
    Solution sol;

    long long arr1[] = {-2, 0, 1, 3};
    int n1 = 4;
    long long sum1 = 2;
    cout << sol.countTriplets(n1, sum1, arr1) << endl;  // Output: 2

    long long arr2[] = {5, 1, 3, 4, 7};
    int n2 = 5;
    long long sum2 = 12;
    cout << sol.countTriplets(n2, sum2, arr2) << endl;  // Output: 4

    return 0;
}
