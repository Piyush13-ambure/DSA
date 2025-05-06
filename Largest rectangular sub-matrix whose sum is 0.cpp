/*Given a matrix mat[][]. Find the size of the largest sub-matrix whose sum is equal to zero. The size of a matrix is the product of rows and columns. A sub-matrix is a matrix obtained from the given matrix by deletion of several (possibly, zero or all) rows/columns from the beginning and several (possibly, zero or all) rows/columns from the end.*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int zeroSumSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxSize = 0;

        // Iterate over all pairs of rows
        for (int top = 0; top < n; ++top) {
            vector<int> temp(m, 0);
            for (int bottom = top; bottom < n; ++bottom) {
                // Sum columns between top and bottom rows
                for (int col = 0; col < m; ++col) {
                    temp[col] += mat[bottom][col];
                }

                // Use hashmap to find the longest subarray with sum = 0
                unordered_map<int, int> map;
                int curr_sum = 0;
                map[0] = -1;
                for (int i = 0; i < m; ++i) {
                    curr_sum += temp[i];
                    if (map.find(curr_sum) != map.end()) {
                        int len = i - map[curr_sum];
                        int size = len * (bottom - top + 1);
                        maxSize = max(maxSize, size);
                    } else {
                        map[curr_sum] = i;
                    }
                }
            }
        }

        return maxSize;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat1 = {{9, 7, 16, 5}, {1, -6, -7, 3}, {1, 8, 7, 9}, {7, -2, 0, 10}};
    vector<vector<int>> mat2 = {{1, 2, 3}, {-3, -2, -1}, {1, 7, 5}};
    vector<vector<int>> mat3 = {{1, -1}, {-1, 1}};

    cout << "Output for mat1: " << sol.zeroSumSubmat(mat1) << endl;  // Output: 6
    cout << "Output for mat2: " << sol.zeroSumSubmat(mat2) << endl;  // Output: 6
    cout << "Output for mat3: " << sol.zeroSumSubmat(mat3) << endl;  // Output: 4

    return 0;
}
