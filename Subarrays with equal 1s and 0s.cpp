//Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        unordered_map<int, int> prefixSumCount;
        int sum = 0;
        long long int count = 0;
        
        // Initialize map with 0 sum occurring once
        prefixSumCount[0] = 1;

        for (int i = 0; i < n; i++) {
            // Convert 0 to -1
            sum += (arr[i] == 0) ? -1 : 1;
            
            // If the sum has been seen before, add the count
            if (prefixSumCount.find(sum) != prefixSumCount.end()) {
                count += prefixSumCount[sum];
            }

            // Increment the prefix sum occurrence
            prefixSumCount[sum]++;
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    int arr1[] = {1, 0, 0, 1, 0, 1, 1};
    int n1 = 7;
    cout << sol.countSubarrWithEqualZeroAndOne(arr1, n1) << endl; // Output: 8

    int arr2[] = {1, 1, 1, 1, 0};
    int n2 = 5;
    cout << sol.countSubarrWithEqualZeroAndOne(arr2, n2) << endl; // Output: 1

    return 0;
}
