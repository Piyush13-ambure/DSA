/*Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any array. You can switch from one array to another array only at the common elements.

Note:  When we switch from one array to other,  we need to consider the common element only once in the result.*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int m = arr1.size();
        int n = arr2.size();
        int i = 0, j = 0;
        int result = 0, sum1 = 0, sum2 = 0;

        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                sum1 += arr1[i++];
            } else if (arr1[i] > arr2[j]) {
                sum2 += arr2[j++];
            } else { // common element
                result += max(sum1, sum2) + arr1[i]; // add only once
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }

        // Add remaining elements of arr1
        while (i < m) {
            sum1 += arr1[i++];
        }

        // Add remaining elements of arr2
        while (j < n) {
            sum2 += arr2[j++];
        }

        result += max(sum1, sum2);

        return result;
    }
};

// Main function to test the code
int main() {
    Solution sol;

    vector<int> arr1 = {2, 3, 7, 10, 12};
    vector<int> arr2 = {1, 5, 7, 8};
    cout << "Output: " << sol.maxPathSum(arr1, arr2) << endl; // Expected: 35

    arr1 = {1, 2, 3};
    arr2 = {3, 4, 5};
    cout << "Output: " << sol.maxPathSum(arr1, arr2) << endl; // Expected: 15

    return 0;
}
