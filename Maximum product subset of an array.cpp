/*Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be a single element also.
Since the product can be large, return it modulo 109 + 7.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        
        long long product = 1;
        int negative_count = 0, zero_count = 0;
        int max_negative = INT_MIN;
        
        for (int num : arr) {
            if (num == 0) {
                zero_count++;
                continue;
            }
            if (num < 0) {
                negative_count++;
                max_negative = max(max_negative, num);
            }
            product = (product * num) % MOD;
        }
        
        // If all are zeros
        if (zero_count == n) return 0;
        
        // If odd number of negatives, remove the largest negative
        if (negative_count % 2 != 0) {
            if (negative_count == 1 && zero_count > 0 && negative_count + zero_count == n) 
                return 0; // If only one negative and rest are zeroes
            product = (product * pow(max_negative, MOD-2, MOD)) % MOD; // Modular inverse
        }
        
        return (product + MOD) % MOD; // Ensure non-negative result
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {-1, 0, -2, 4, 3};
    cout << sol.findMaxProduct(arr1) << endl; // Output: 24

    vector<int> arr2 = {-1, 0};
    cout << sol.findMaxProduct(arr2) << endl; // Output: 0

    vector<int> arr3 = {5};
    cout << sol.findMaxProduct(arr3) << endl; // Output: 5

    return 0;
}
