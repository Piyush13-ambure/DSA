/*In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop = 0, rotateBottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target)
                return -1; // Not possible to make this target
            else if (tops[i] != target)
                rotateTop++; // Need to rotate to get target in top
            else if (bottoms[i] != target)
                rotateBottom++; // Need to rotate to get target in bottom
        }
        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = check(tops[0], tops, bottoms);
        if (res != -1) return res;
        return check(bottoms[0], tops, bottoms);
    }
};

// Test driver
int main() {
    Solution sol;
    vector<int> tops1 = {2,1,2,4,2,2};
    vector<int> bottoms1 = {5,2,6,2,3,2};
    cout << "Output: " << sol.minDominoRotations(tops1, bottoms1) << endl; // Output: 2

    vector<int> tops2 = {3,5,1,2,3};
    vector<int> bottoms2 = {3,6,3,3,4};
    cout << "Output: " << sol.minDominoRotations(tops2, bottoms2) << endl; // Output: -1

    return 0;
}
