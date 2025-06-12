/*Find the number of occurrences of a given search word in a 2d-Array of characters where the word can go up, down, left, right, and around 90-degree bends.
Note: While making a word you can use one cell only once.

Your task:
You don't need to read input or print anything. Your task is to complete the function findOccurrence() which takes the mat containing N*M 2-d array of characters and target as input parameters and returns the number of occurrences of the target.
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int R, C;
    vector<vector<char>> board;
    string word;
    int wordLen;

    // Directions: up, down, left, right
    int dirX[4] = {-1, 1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};

    int dfs(int x, int y, int idx, vector<vector<bool>>& visited) {
        if (board[x][y] != word[idx])
            return 0;
        if (idx == wordLen - 1)
            return 1;

        visited[x][y] = true;
        int count = 0;

        for (int d = 0; d < 4; ++d) {
            int newX = x + dirX[d];
            int newY = y + dirY[d];
            if (newX >= 0 && newX < R && newY >= 0 && newY < C && !visited[newX][newY]) {
                count += dfs(newX, newY, idx + 1, visited);
            }
        }

        visited[x][y] = false; // backtrack
        return count;
    }

    int findOccurrence(vector<vector<char>>& mat, string target) {
        R = mat.size();
        C = mat[0].size();
        board = mat;
        word = target;
        wordLen = word.length();

        int total = 0;
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (board[i][j] == word[0]) {
                    total += dfs(i, j, 0, visited);
                }
            }
        }

        return total;
    }
};

// ---------- Main Function for Testing ----------
int main() {
    Solution sol;

    // Example 1
    vector<vector<char>> mat1 = {
        {'S','N','B','S','N'},
        {'B','A','K','E','A'},
        {'B','K','B','B','K'},
        {'S','E','B','S','E'}
    };
    string target1 = "SNAKES";
    cout << "Output for Example 1: " << sol.findOccurrence(mat1, target1) << endl; // Expected: 3

    // Example 2
    vector<vector<char>> mat2 = {
        {'c','a','t'},
        {'a','t','c'},
        {'c','t','a'}
    };
    string target2 = "cat";
    cout << "Output for Example 2: " << sol.findOccurrence(mat2, target2) << endl; // Expected: 5

    return 0;
}
