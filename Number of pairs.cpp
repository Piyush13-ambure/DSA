//Given two positive integer arrays arr and brr, find the number of pairs such that xy > yx (raised to power of) where x is an element from arr and y is an element from brr.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to count valid pairs (x, y) such that x^y > y^x
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        sort(brr.begin(), brr.end());  // Sort brr for binary search

        // Precompute count of numbers in brr
        int count[5] = {0};  
        for (int y : brr) {
            if (y < 5) count[y]++;
        }

        long long result = 0;
        for (int x : arr) {
            if (x == 1) continue; // x = 1 never contributes

            int idx = upper_bound(brr.begin(), brr.end(), x) - brr.begin();
            result += (brr.size() - idx); // Count elements greater than x

            // Handle special cases separately
            result += count[1]; // All (x, 1) pairs are valid

            if (x == 2) {
                result -= (count[3] + count[4]); // Exception: 2^3 < 3^2 and 2^4 < 4^2
            }
            if (x == 3) {
                result += count[2]; // 3^2 > 2^3 case
            }
        }
        return result;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    vector<int> arr1 = {2, 1, 6}, brr1 = {1, 5};
    cout << "Output: " << sol.countPairs(arr1, brr1) << endl;  // Expected: 3

    vector<int> arr2 = {2, 3, 4, 5}, brr2 = {1, 2, 3};
    cout << "Output: " << sol.countPairs(arr2, brr2) << endl;  // Expected: 5

    return 0;
}
