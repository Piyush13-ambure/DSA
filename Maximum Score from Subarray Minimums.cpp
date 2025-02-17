//Given an array arr[], with 0-based indexing, select any two indexes, i and j such that i < j. From the subarray arr[i...j], select the smallest and second smallest numbers and add them, you will get the score for that subarray. Return the maximum possible score across all the subarrays of array arr[].



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum pair sum of adjacent elements
    int pairWithMaxSum(vector<int> &arr) {
        int maxSum = 0; // Initialize max sum
        for (int i = 1; i < arr.size(); i++) {
            maxSum = max(maxSum, arr[i] + arr[i - 1]); // Compare adjacent pairs
        }
        return maxSum;
    }
};

// Main function for testing
int main() {
    vector<int> arr = {4, 3, 1, 5, 6}; // Example input
    Solution obj;
    cout << obj.pairWithMaxSum(arr) << endl; // Expected output: 11

    arr = {5, 4, 3, 1, 6}; // Another test case
    cout << obj.pairWithMaxSum(arr) << endl; // Expected output: 9

    return 0;
}
