/*Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.*/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd_count = 0, even_count = 1; // even_count starts at 1 for prefix sum=0
        int prefix_sum = 0, result = 0;

        for (int num : arr) {
            prefix_sum += num;

            if (prefix_sum % 2 == 0) {
                result = (result + odd_count) % MOD;
                even_count++; // Current prefix sum is even
            } else {
                result = (result + even_count) % MOD;
                odd_count++; // Current prefix sum is odd
            }
        }

        return result;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    vector<int> arr1 = {1, 3, 5};
    cout << "Output: " << sol.numOfSubarrays(arr1) << endl; // Expected: 4

    vector<int> arr2 = {2, 4, 6};
    cout << "Output: " << sol.numOfSubarrays(arr2) << endl; // Expected: 0

    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Output: " << sol.numOfSubarrays(arr3) << endl; // Expected: 16

    return 0;
}
