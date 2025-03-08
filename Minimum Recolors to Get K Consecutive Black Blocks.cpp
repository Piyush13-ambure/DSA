/*You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minOperations = k; // Worst case: change all k elements to 'B'
        int whiteCount = 0;

        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }
        minOperations = whiteCount;

        // Slide the window across the string
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') whiteCount++; // Add new element
            if (blocks[i - k] == 'W') whiteCount--; // Remove old element

            minOperations = min(minOperations, whiteCount);
        }
        
        return minOperations;
    }
};

int main() {
    Solution sol;
    cout << sol.minimumRecolors("WBBWWBBWBW", 7) << endl;  // Output: 3
    cout << sol.minimumRecolors("WBWBBBW", 2) << endl;     // Output: 0
    return 0;
}
