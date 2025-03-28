/*Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1; // Start filling from 1

        while (num <= n * n) {
            // Move left to right along the top row
            for (int i = left; i <= right; i++) 
                matrix[top][i] = num++;
            top++;

            // Move top to bottom along the right column
            for (int i = top; i <= bottom; i++) 
                matrix[i][right] = num++;
            right--;

            // Move right to left along the bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) 
                    matrix[bottom][i] = num++;
                bottom--;
            }

            // Move bottom to top along the left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) 
                    matrix[i][left] = num++;
                left++;
            }
        }

        return matrix;
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    Solution solution;
    
    int n;
    cout << "Enter matrix size (n): ";
    cin >> n;

    vector<vector<int>> result = solution.generateMatrix(n);
    
    cout << "Spiral Matrix:" << endl;
    printMatrix(result);

    return 0;
}
