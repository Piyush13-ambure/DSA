/*Given a binary matrix mat[][] of dimensions NxM such that 1 denotes land and 0 denotes water. Find the number of closed islands in the given matrix.
An island is a 4-directional(up,right,down and left) connected part of 1's.

Note: A closed island is a group of 1s surrounded by only 0s on all the boundaries (except diagonals). In simple words, a closed island is an island whose none of the 1s lie on the edges of the matrix.
Your task:
You dont need to read input or print anything. Your task is to complete the function closedIslands() which takes two integers N and M, and a 2D binary matrix mat as input parameters and returns the number of closed islands.*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& mat, int i, int j, int N, int M) {
        if (i < 0 || j < 0 || i >= N || j >= M || mat[i][j] == 0)
            return;
        mat[i][j] = 0;
        dfs(mat, i + 1, j, N, M);
        dfs(mat, i - 1, j, N, M);
        dfs(mat, i, j + 1, N, M);
        dfs(mat, i, j - 1, N, M);
    }

    int closedIslands(vector<vector<int>>& mat, int N, int M) {
        // Remove land connected to borders
        for (int i = 0; i < N; ++i) {
            if (mat[i][0] == 1) dfs(mat, i, 0, N, M);
            if (mat[i][M - 1] == 1) dfs(mat, i, M - 1, N, M);
        }

        for (int j = 0; j < M; ++j) {
            if (mat[0][j] == 1) dfs(mat, 0, j, N, M);
            if (mat[N - 1][j] == 1) dfs(mat, N - 1, j, N, M);
        }

        int count = 0;
        for (int i = 1; i < N - 1; ++i) {
            for (int j = 1; j < M - 1; ++j) {
                if (mat[i][j] == 1) {
                    dfs(mat, i, j, N, M);
                    ++count;
                }
            }
        }
        return count;
    }
};

// Sample main to test the implementation
int main() {
    Solution sol;

    int N = 5, M = 8;
    vector<vector<int>> mat = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 0, 0, 1},
        {0, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1}
    };

    cout << "Number of closed islands: " << sol.closedIslands(mat, N, M) << endl;

    return 0;
}
