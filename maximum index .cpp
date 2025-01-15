//Given an array, arr[] of non-negative integers. The task is to return the maximum of j - i (i<=j) subjected to the constraint of arr[i] <= arr[j].
//  maximum index
//  Created by piyush ambure on 15/01/25.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIndexDiff(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> leftMin(n), rightMax(n);

        // Precompute leftMin array
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], arr[i]);
        }

        // Precompute rightMax array
        rightMax[n - 1] = arr[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            rightMax[j] = max(rightMax[j + 1], arr[j]);
        }

        // Two-pointer traversal
        int i = 0, j = 0, maxDiff = 0;
        while (i < n && j < n) {
            if (leftMin[i] <= rightMax[j]) {
                maxDiff = max(maxDiff, j - i);
                j++;
            } else {
                i++;
            }
        }

        return maxDiff;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 5, 4, 2};
    int result = sol.maxIndexDiff(arr);
    cout << "Maximum index difference: " << result << endl; // Expected Output: 2
    return 0;
}

