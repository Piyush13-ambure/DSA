/*Given a matrix mat[][] of size n × m and an integer x, find the number of square submatrices whose sum of elements is equal to x.*/

class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int res = 0;
        int n = mat.size();
        int m = mat[0].size();

        // Compute row-wise prefix sum
        vector<vector<int>> rowPrefix = mat;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                rowPrefix[i][j] += rowPrefix[i][j - 1];

        int maxSize = min(n, m);

        for (int size = 1; size <= maxSize; size++) {
            for (int i = 0; i <= m - size; i++) {
                int j = i + size - 1;
                int sum = 0;

                for (int row = 0; row < size - 1; row++) {
                    sum += rowPrefix[row][j] - (i > 0 ? rowPrefix[row][i - 1] : 0);
                }

                for (int row = size - 1; row < n; row++) {
                    sum += rowPrefix[row][j] - (i > 0 ? rowPrefix[row][i - 1] : 0);

                    if (sum == x)
                        res++;

                    sum -= rowPrefix[row - size + 1][j] -
                           (i > 0 ? rowPrefix[row - size + 1][i - 1] : 0);
                }
            }
        }

        return res;
    }
};
