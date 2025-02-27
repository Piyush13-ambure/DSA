//Given an array, arr[] of distinct elements, and a number x, find if there is a pair in arr[] with a product equal to x. Return true if there exists such pair otherwise false.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isProduct(vector<int> arr, long long x) {
        unordered_set<long long> seen;
        int zeroCount = 0;

        for (long long num : arr) {
            if (num == 0) {
                zeroCount++;
                if (x == 0 && zeroCount > 1) return true; // Need at least 2 zeroes for x = 0
                continue;
            }

            if (x % num == 0) { // Ensure x is divisible by num
                long long complement = x / num;
                if (seen.count(complement)) return true;
            }

            seen.insert(num);
        }
        return false;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> arr1 = {10, 20, 9, 40};
    long long x1 = 400;
    cout << sol.isProduct(arr1, x1) << endl; // Output: true

    vector<int> arr2 = {-10, 20, 9, -40};
    long long x2 = 30;
    cout << sol.isProduct(arr2, x2) << endl; // Output: false

    return 0;
}
