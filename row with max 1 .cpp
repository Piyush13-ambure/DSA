//You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to find the row with the maximum number of 1s
    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxRowIndex = -1;
        int maxCount = 0;
        int n = arr.size(); // Number of rows
        if (n == 0) return -1; // Handle empty input
        int m = arr[0].size(); // Number of columns
        
        int j = m - 1; // Start at the last column
        for (int i = 0; i < n; i++) {
            // Move left while 1s are found in the current row
            while (j >= 0 && arr[i][j] == 1) {
                j--;
                maxRowIndex = i; // Update the row index
            }
        }

        // If no 1s were found, maxRowIndex will remain -1
        return maxRowIndex;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    vector<vector<int>> arr1 = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 1}
    };

    cout << "Row with max 1s: " << solution.rowWithMax1s(arr1) << endl;

    vector<vector<int>> arr2 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    cout << "Row with max 1s: " << solution.rowWithMax1s(arr2) << endl;

    vector<vector<int>> arr3 = {
        {0, 1},
        {1, 1},
        {0, 0}
    };

    cout << "Row with max 1s: " << solution.rowWithMax1s(arr3) << endl;

    return 0;
}
