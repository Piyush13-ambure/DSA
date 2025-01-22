//Given an array arr containing both positive and negative integers, the task is to compute the length of the largest subarray that has a sum of 0.


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    // Function to find the length of the largest subarray with sum 0
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> prefixSumMap; // To store prefix sums and their first occurrence indices
        int maxLength = 0;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // If sum is 0, we found a subarray starting from index 0
            if (sum == 0) {
                maxLength = i + 1;
            }

            // If the sum was seen before, update maxLength
            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[sum]);
            } else {
                // Otherwise, store the current sum with its index
                prefixSumMap[sum] = i;
            }
        }

        return maxLength;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    vector<int> arr1 = {1, 2, -3, 3, 1, -4, 2, 1};
    cout << "Length of the largest subarray with sum 0: " << solution.maxLen(arr1) << endl;

    vector<int> arr2 = {1, -1, 3, -2, 2};
    cout << "Length of the largest subarray with sum 0: " << solution.maxLen(arr2) << endl;

    vector<int> arr3 = {3, 1, -4, 2, 1};
    cout << "Length of the largest subarray with sum 0: " << solution.maxLen(arr3) << endl;

    return 0;
}
