//Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any array. You can switch from one array to another array only at the common elements.

//Note:  When we switch from one array to other,  we need to consider the common element only once in the result.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathSum(vector<int>& arr1, vector<int>& arr2) {
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0, maxSum = 0;
        
        int n = arr1.size(), m = arr2.size();
        
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                sum1 += arr1[i++];
            } else if (arr2[j] < arr1[i]) {
                sum2 += arr2[j++];
            } else {
                // We reached a common element, pick max sum path before switching
                maxSum += max(sum1, sum2) + arr1[i];  // Add common element once
                sum1 = sum2 = 0;  // Reset both sums
                i++;
                j++;
            }
        }

        // Add remaining elements from arr1
        while (i < n) {
            sum1 += arr1[i++];
        }
        
        // Add remaining elements from arr2
        while (j < m) {
            sum2 += arr2[j++];
        }

        // Add the maximum remaining sum
        maxSum += max(sum1, sum2);

        return maxSum;
    }
};

// Main function to test the implementation
int main() {
    Solution obj;
    vector<int> arr1 = {2, 3, 7, 10, 12};
    vector<int> arr2 = {1, 5, 7, 8};
    cout << obj.maxPathSum(arr1, arr2) << endl;  // Output: 35

    vector<int> arr3 = {1, 2, 3};
    vector<int> arr4 = {3, 4, 5};
    cout << obj.maxPathSum(arr3, arr4) << endl;  // Output: 15

    return 0;
}
