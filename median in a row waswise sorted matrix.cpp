//Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int median(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        // Find the minimum and maximum elements in the matrix
        for (int i = 0; i < rows; i++) {
            minVal = min(minVal, mat[i][0]); // First element in the row
            maxVal = max(maxVal, mat[i][cols - 1]); // Last element in the row
        }

        int desired = (rows * cols + 1) / 2; // Index of the median (1-based)
        int result = 0;

        // Binary search for the median
        while (minVal <= maxVal) {
            int mid = minVal + (maxVal - minVal) / 2;

            // Count of elements less than or equal to `mid`
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (count < desired) {
                minVal = mid + 1;
            } else {
                result = mid;
                maxVal = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns (odd x odd): ";
    cin >> rows >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix (row-wise sorted):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    Solution solution;
    int medianValue = solution.median(mat);

    cout << "The median of the matrix is: " << medianValue << endl;

    return 0;
}
