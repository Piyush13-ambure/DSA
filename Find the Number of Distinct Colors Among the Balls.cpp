/*You are given an integer limit and a 2D array queries of size n x 2.

There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.

Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

Note that when answering a query, lack of a color will not be considered as a color.*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_color;  // Stores the color of each ball
        unordered_map<int, int> color_count; // Stores count of each color
        unordered_set<int> unique_colors;    // Stores distinct colors
        vector<int> result;

        for (const auto& query : queries) {
            int ball = query[0], color = query[1];

            // If the ball already has a color
            if (ball_color.count(ball)) {
                int old_color = ball_color[ball];
                color_count[old_color]--;

                // If no balls have this color anymore, remove it from unique colors
                if (color_count[old_color] == 0) {
                    unique_colors.erase(old_color);
                }
            }

            // Assign the new color to the ball
            ball_color[ball] = color;
            color_count[color]++;
            unique_colors.insert(color);

            // Store the number of distinct colors
            result.push_back(unique_colors.size());
        }

        return result;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    
    vector<vector<int>> queries1 = {{1,4}, {2,5}, {1,3}, {3,4}};
    vector<int> result1 = solution.queryResults(4, queries1);
    for (int num : result1) cout << num << " ";
    cout << endl;

    vector<vector<int>> queries2 = {{0,1}, {1,2}, {2,2}, {3,4}, {4,5}};
    vector<int> result2 = solution.queryResults(4, queries2);
    for (int num : result2) cout << num << " ";
    cout << endl;

    return 0;
}
