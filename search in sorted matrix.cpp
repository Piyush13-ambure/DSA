//Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
//Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m, col = mid % m;

            if (mat[row][col] == x)
                return true;
            else if (mat[row][col] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };
    int x = 9;
    cout << (sol.searchMatrix(mat, x) ? "Found" : "Not Found") << endl; 
    return 0;
}

