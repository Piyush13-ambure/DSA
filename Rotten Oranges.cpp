//Given a matrix where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
//0 : Empty cell
//1 : Cells have fresh oranges
//2 : Cells have rotten oranges

//We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i, j] can rot other fresh orange at indexes [i-1, j], [i+1, j], [i, j-1], [i,j+1] (up, down, left and right) in unit time.

//Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.




#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<pair<int, int>, int>> q; // Queue to store {cell coordinates, time}
        int freshCount = 0; // Count of fresh oranges

        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 2) {
                    q.push({{i, j}, 0}); // Push rotten orange with time 0
                } else if (mat[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;

        // BFS traversal to rot all fresh oranges
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            time = curr.second;

            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Check if the new cell is within bounds and has a fresh orange
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && mat[newX][newY] == 1) {
                    mat[newX][newY] = 2; // Mark orange as rotten
                    freshCount--; // Reduce fresh orange count
                    q.push({{newX, newY}, time + 1}); // Push new cell with incremented time
                }
            }
        }

        // If there are still fresh oranges, return -1
        return (freshCount == 0) ? time : -1;
    }
};

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));
    cout << "Enter the matrix values (0, 1, 2):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    Solution sol;
    int result = sol.orangesRotting(mat);

    if (result == -1) {
        cout << "Not all oranges can be rotten.\n";
    } else {
        cout << "Minimum time to rot all oranges: " << result << "\n";
    }

    return 0;
}
