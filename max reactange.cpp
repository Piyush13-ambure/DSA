//Given a binary matrix mat[][] of size n * m. Find the maximum area of a rectangle formed only of 1s in the given matrix.


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to find the maximum area in a histogram
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    // Function to calculate the maximum area of a rectangle in a binary matrix
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the current cell is 1, add 1 to the height, otherwise reset it to 0
                heights[j] = mat[i][j] == 1 ? heights[j] + 1 : 0;
            }
            // Find the maximum area for the current row histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the binary matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution solution;
    int result = solution.maxArea(mat);

    cout << "The maximum area of a rectangle of 1s is: " << result << endl;

    return 0;
}
