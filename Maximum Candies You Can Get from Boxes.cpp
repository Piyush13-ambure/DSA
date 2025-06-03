/*You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:

status[i] is 1 if the ith box is open and 0 if the ith box is closed,
candies[i] is the number of candies in the ith box,
keys[i] is a list of the labels of the boxes you can open after opening the ith box.
containedBoxes[i] is a list of the boxes you found inside the ith box.
You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.

Return the maximum number of candies you can get following the rules above.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> hasBox(n, false), hasKey(n, false), visited(n, false);
        queue<int> q;
        
        for (int box : initialBoxes) {
            hasBox[box] = true;
            q.push(box);
        }
        
        int totalCandies = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool progress = false;  // flag to indicate progress this round
            
            for (int i = 0; i < size; ++i) {
                int box = q.front(); q.pop();
                
                if (visited[box]) continue;
                
                if (status[box] == 1 || hasKey[box]) {
                    visited[box] = true;
                    totalCandies += candies[box];
                    progress = true;
                    
                    // collect keys
                    for (int key : keys[box]) {
                        hasKey[key] = true;
                        if (hasBox[key] && !visited[key])
                            q.push(key);
                    }
                    
                    // collect contained boxes
                    for (int contained : containedBoxes[box]) {
                        hasBox[contained] = true;
                        if (!visited[contained])
                            q.push(contained);
                    }
                } else {
                    q.push(box);  // try again later when key might be available
                }
            }
            if (!progress) break;  // no further progress possible
        }

        return totalCandies;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    // Example 1
    vector<int> status1 = {1, 0, 1, 0};
    vector<int> candies1 = {7, 5, 4, 100};
    vector<vector<int>> keys1 = {{}, {}, {1}, {}};
    vector<vector<int>> contained1 = {{1, 2}, {3}, {}, {}};
    vector<int> initial1 = {0};
    cout << "Output 1: " << sol.maxCandies(status1, candies1, keys1, contained1, initial1) << endl;

    // Example 2
    vector<int> status2 = {1, 0, 0, 0, 0, 0};
    vector<int> candies2 = {1, 1, 1, 1, 1, 1};
    vector<vector<int>> keys2 = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    vector<vector<int>> contained2 = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    vector<int> initial2 = {0};
    cout << "Output 2: " << sol.maxCandies(status2, candies2, keys2, contained2, initial2) << endl;

    return 0;
}
