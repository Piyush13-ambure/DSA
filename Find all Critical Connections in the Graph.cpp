/*A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges where each vertex is distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

Note: You can return connections in any order.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int time = 0;
    void dfs(int u, int parent, vector<int>& disc, vector<int>& low, vector<vector<int>>& adj, vector<vector<int>>& result) {
        disc[u] = low[u] = ++time;

        for (int v : adj[u]) {
            if (v == parent) continue;  // Skip the parent

            if (disc[v] == -1) {
                dfs(v, u, disc, low, adj, result);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    result.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(v, -1), low(v, -1);
        vector<vector<int>> result;

        dfs(0, -1, disc, low, adj, result);
        return result;
    }
};

// Main function to demonstrate the use
int main() {
    Solution sol;
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    
    vector<vector<int>> edges;
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<vector<int>> critical = sol.criticalConnections(v, edges);
    cout << "Critical connections:\n";
    for (auto& edge : critical) {
        cout << edge[0] << " " << edge[1] << "\n";
    }

    return 0;
}
