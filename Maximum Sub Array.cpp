//Given an array of integers, find the contiguous subarray with the maximum sum that contains only non-negative numbers. If multiple subarrays have the same sum, return the one with the smallest starting index.

//A subarray is a contiguous non-empty sequence of elements within an array.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int maxSum = 0, currentSum = 0;
        int maxStart = -1, maxEnd = -1, start = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                currentSum += arr[i];
                
                // Update best subarray if needed
                if (currentSum > maxSum || 
                   (currentSum == maxSum && (maxStart == -1 || start < maxStart))) {
                    maxSum = currentSum;
                    maxStart = start;
                    maxEnd = i;
                }
            } else {
                // Reset on negative number
                currentSum = 0;
                start = i + 1;
            }
        }
        
        // If no non-negative subarray exists
        if (maxStart == -1) return {-1};

        return vector<int>(arr.begin() + maxStart, arr.begin() + maxEnd + 1);
    }
};

// Main function for testing
int main() {
    vector<int> arr = {1, 2, 5, -7, 2, 6};
    
    Solution sol;
    vector<int> result = sol.findSubarray(arr);
    
    // Print result
    if (result.empty()) {
        cout << "No non-negative subarray found";
    } else {
        for (int num : result) {
            cout << num << " ";
        }
    }
    cout << endl;

    return 0;
}
