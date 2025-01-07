//
//  main.cpp
//  Vectors
//
//  Created by piyush ambure on 04/01/25.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubarrayWithSum(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, sum = 0;

        for (int right = 0; right < n; ++right) {
            // Add the current element to the sum
            sum += arr[right];

            // Shrink the window from the left if the sum exceeds the target
            while (sum > target && left <= right) {
                sum -= arr[left];
                ++left;
            }

            // Check if the current window's sum equals the target
            if (sum == target) {
                return {left + 1, right + 1}; // Return 1-based indices
            }
        }

        // If no subarray is found, return [-1]
        return {-1};
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;

    vector<int> result = solution.findSubarrayWithSum(arr, target);

    if (result.size() == 1 && result[0] == -1) {
        cout << "[-1]" << endl;
    } else {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }

    return 0;
}
