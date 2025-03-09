/*There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlternating(vector<int>& colors, int start, int k) {
        for (int i = 1; i < k; i++) {
            if (colors[(start + i) % colors.size()] == colors[(start + i - 1) % colors.size()]) {
                return false; // Not alternating
            }
        }
        return true;
    }

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (isAlternating(colors, i, k)) {
                count++;
            }
        }
        
        return count;
    }
};

// Driver Code
int main() {
    Solution obj;
    
    vector<int> colors1 = {0,1,0,1,0};
    int k1 = 3;
    cout << obj.numberOfAlternatingGroups(colors1, k1) << endl; // Output: 3

    vector<int> colors2 = {0,1,0,0,1,0,1};
    int k2 = 6;
    cout << obj.numberOfAlternatingGroups(colors2, k2) << endl; // Output: 2

    vector<int> colors3 = {1,1,0,1};
    int k3 = 4;
    cout << obj.numberOfAlternatingGroups(colors3, k3) << endl; // Output: 0

    return 0;
}
