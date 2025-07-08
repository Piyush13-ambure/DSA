/*Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. Level of root is 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function optimalSearchTree() which takes the array keys[], freq[] and their size n as input parameters and returns the total cost of all the searches is as small as possible.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to calculate sum of frequencies in a range
    int sum(int freq[], int i, int j) {
        int s = 0;
        for (int k = i; k <= j; k++)
            s += freq[k];
        return s;
    }

    int optimalSearchTree(int keys[], int freq[], int n) {
        // cost[i][j] = Optimal cost of BST that can be built from keys[i] to keys[j]
        vector<vector<int>> cost(n, vector<int>(n, 0));

        // cost for single key trees
        for (int i = 0; i < n; i++)
            cost[i][i] = freq[i];

        // L is chain length
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                cost[i][j] = INT_MAX;

                // Try making all keys in interval keys[i..j] as root
                for (int r = i; r <= j; r++) {
                    int c = 0;
                    if (r > i)
                        c += cost[i][r - 1];
                    if (r < j)
                        c += cost[r + 1][j];
                    c += sum(freq, i, j); // Add sum of frequencies

                    cost[i][j] = min(cost[i][j], c);
                }
            }
        }

        return cost[0][n - 1];
    }
};

// Example main function
int main() {
    Solution obj;
    
    int n1 = 2;
    int keys1[] = {10, 12};
    int freq1[] = {34, 50};
    cout << "Output: " << obj.optimalSearchTree(keys1, freq1, n1) << endl; // Expected: 118

    int n2 = 3;
    int keys2[] = {10, 12, 20};
    int freq2[] = {34, 8, 50};
    cout << "Output: " << obj.optimalSearchTree(keys2, freq2, n2) << endl; // Expected: 142

    return 0;
}
 
