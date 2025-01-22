//Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

//Note: It is guaranteed that the output fits in a 32-bit integer.

#include <iostream>
#include <vector>
#include <algorithm> // For max and min functions
using namespace std;

// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int maxProduct = arr[0];
        int minProduct = arr[0];
        int result = arr[0];

        for (int i = 1; i < n; ++i) {
            if (arr[i] < 0) {
                swap(maxProduct, minProduct);
            }
            maxProduct = max(arr[i], maxProduct * arr[i]);
            minProduct = min(arr[i], minProduct * arr[i]);
            result = max(result, maxProduct);
        }
        return result;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<int> arr = {2, 3, -2, 4};
    
    cout << "Maximum Product Subarray: " << solution.maxProduct(arr) << endl;
    
    vector<int> arr2 = {-2, 0, -1};
    cout << "Maximum Product Subarray: " << solution.maxProduct(arr2) << endl;

    vector<int> arr3 = {6, -3, -10, 0, 2};
    cout << "Maximum Product Subarray: " << solution.maxProduct(arr3) << endl;

    return 0;
}
