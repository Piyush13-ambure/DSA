/*Vertex cover of an undirected graph is a list of vertices such that every vertex not in the vertex cover shares their every edge with the vertices in the vertex cover. In other words, for every edge in the graph, atleast one of the endpoints of the graph should belong to the vertex cover. You will be given an undirected graph G, and your task is to determine the smallest possible size of a vertex cover.
Your Tsk:  
You don't need to read input or print anything. Your task is to complete the function vertexCover() which takes the edge list and an integer n for the number of nodes of the graph as input parameters and returns the size of the smallest possible vertex cover.


*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        int minCoverSize = INT_MAX;
        int totalSubsets = 1 << n; // 2^n subsets

        // Try all subsets of vertices
        for (int mask = 0; mask < totalSubsets; ++mask) {
            bool isValid = true;

            // Check if this subset covers all edges
            for (auto &edge : edges) {
                int u = edge.first - 1; // converting to 0-based
                int v = edge.second - 1;

                // If neither u nor v is in the subset
                if (((mask >> u) & 1) == 0 && ((mask >> v) & 1) == 0) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                // Count number of set bits = size of vertex cover
                int count = __builtin_popcount(mask);
                minCoverSize = min(minCoverSize, count);
            }
        }

        return minCoverSize;
    }
};

// Main function to test the vertexCover implementation
int main() {
    Solution sol;

    // Example 1
    int N1 = 5;
    vector<pair<int, int>> edges1 = {
        {1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}
    };
    cout << "Minimum Vertex Cover Size (Example 1): "
         << sol.vertexCover(N1, edges1) << endl;

    // Example 2
    int N2 = 2;
    vector<pair<int, int>> edges2 = {
        {1, 2}
    };
    cout << "Minimum Vertex Cover Size (Example 2): "
         << sol.vertexCover(N2, edges2) << endl;

    return 0;
}
