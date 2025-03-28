/*You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();

        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> result(k, 0);

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int count = 0, idx = 0;
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for (int q : sortedQueries) {
            while (!pq.empty() && pq.top().first < q) {
                auto [val, pos] = pq.top();
                pq.pop();
                count++;

                int x = pos.first, y = pos.second;
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                        pq.push({grid[nx][ny], {nx, ny}});
                        visited[nx][ny] = true;
                    }
                }
            }
            result[idx++] = count;
        }

        // Map results back to original query order
        vector<int> finalResult(k);
        for (int i = 0; i < k; i++) {
            finalResult[i] = result[lower_bound(sortedQueries.begin(), sortedQueries.end(), queries[i]) - sortedQueries.begin()];
        }

        return finalResult;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

// Main function
int main() {
    Solution solution;
    
    vector<vector<int>> grid1 = {{1,2,3}, {2,5,7}, {3,5,1}};
    vector<int> queries1 = {5,6,2};
    vector<int> result1 = solution.maxPoints(grid1, queries1);
    printVector(result1); // Output: [5,8,1]

    vector<vector<int>> grid2 = {{5,2,1}, {1,1,2}};
    vector<int> queries2 = {3};
    vector<int> result2 = solution.maxPoints(grid2, queries2);
    printVector(result2); // Output: [0]

    return 0;
}
