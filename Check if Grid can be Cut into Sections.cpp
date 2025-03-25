/*You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        set<int> xCoords, yCoords;

        // Collect unique x and y coordinates
        for (const auto& rect : rectangles) {
            xCoords.insert(rect[0]);
            xCoords.insert(rect[2]);
            yCoords.insert(rect[1]);
            yCoords.insert(rect[3]);
        }

        vector<int> xList(xCoords.begin(), xCoords.end());
        vector<int> yList(yCoords.begin(), yCoords.end());

        // Function to check if valid cuts exist
        auto isValidCut = [](const vector<int>& coords, const vector<vector<int>>& rects, bool isVertical) {
            int size = coords.size();
            for (int i = 1; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    int cut1 = coords[i], cut2 = coords[j];
                    int left = 0, mid = 0, right = 0;

                    for (const auto& rect : rects) {
                        int start = isVertical ? rect[0] : rect[1];
                        int end = isVertical ? rect[2] : rect[3];

                        if (end <= cut1) left++;       // Belongs to left section
                        else if (start >= cut2) right++; // Belongs to right section
                        else mid++;                     // Belongs to the middle section
                    }

                    if (left > 0 && mid > 0 && right > 0) return true;
                }
            }
            return false;
        };

        // Check for vertical cuts
        if (isValidCut(xList, rectangles, true)) return true;
        // Check for horizontal cuts
        if (isValidCut(yList, rectangles, false)) return true;

        return false;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<vector<int>> rectangles1 = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
    cout << sol.checkValidCuts(5, rectangles1) << endl;  // Output: true

    vector<vector<int>> rectangles2 = {{0,0,1,1},{2,0,3,4},{0,2,2,3},{3,0,4,3}};
    cout << sol.checkValidCuts(4, rectangles2) << endl;  // Output: true

    vector<vector<int>> rectangles3 = {{0,2,2,4},{1,0,3,2},{2,2,3,4},{3,0,4,2},{3,2,4,4}};
    cout << sol.checkValidCuts(4, rectangles3) << endl;  // Output: false

    return 0;
}
