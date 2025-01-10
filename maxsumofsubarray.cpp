//
//  main.cpp
//  max sum of an subarray
//
//  Created by piyush ambure on 10/01/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the maximum sum of a subarray
    int maxSubArraySum(const vector<int>& arr) {
        int maxSum = arr[0]; // Initialize max sum as the first element
        int currentSum = arr[0]; // Initialize current sum as the first element

        // Iterate through the array starting from the second element
        for (size_t i = 1; i < arr.size(); i++) {
            // Update currentSum to either the current element or currentSum + current element
            currentSum = max(arr[i], currentSum + arr[i]);

            // Update maxSum if currentSum is greater
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

// Example usage
int main() {
    Solution solution;

    vector<int> arr1 = {2, 3, -8, 7, -1, 2, 3};
    cout << "Maximum Subarray Sum: " << solution.maxSubArraySum(arr1) << endl;

    vector<int> arr2 = {-2, -4};
    cout << "Maximum Subarray Sum: " << solution.maxSubArraySum(arr2) << endl;

    vector<int> arr3 = {5, 4, 1, 7, 8};
    cout << "Maximum Subarray Sum: " << solution.maxSubArraySum(arr3) << endl;

    return 0;
}
