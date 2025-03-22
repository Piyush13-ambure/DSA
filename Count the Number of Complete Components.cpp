/*You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n); // Adjacency list
        
        // Build the adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeCount = 0;

        // Function to perform DFS and find the connected component
        auto dfs = [&](int node, vector<int>& component, auto&& dfs_ref) -> void {
            visited[node] = true;
            component.push_back(node);
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs_ref(neighbor, component, dfs_ref);
                }
            }
        };

        // Iterate through all nodes to find connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, component, dfs);

                // Check if the component is a complete subgraph
                int size = component.size();
                int expectedEdges = (size * (size - 1)) / 2;
                int actualEdges = 0;

                for (int node : component) {
                    actualEdges += adj[node].size();
                }
                
                actualEdges /= 2; // Since the graph is undirected, each edge is counted twice

                if (actualEdges == expectedEdges) {
                    completeCount++;
                }
            }
        }

        return completeCount;
    }
};

// Main function for testing
int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{0,1},{0,2},{1,2},{3,4}};
    cout << sol.countCompleteComponents(6, edges1) << endl; // Expected output: 3

    vector<vector<int>> edges2 = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    cout << sol.countCompleteComponents(6, edges2) << endl; // Expected output: 1

    return 0;
}
