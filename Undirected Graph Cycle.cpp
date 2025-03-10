/*Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle using BFS.
    bool bfsCycleCheck(int src, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q; // Pair stores (current node, parent)
        q.push({src, -1});
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    return true; // Cycle detected
                }
            }
        }
        return false;
    }

    // Function to detect cycle using DFS.
    bool dfsCycleCheck(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCycleCheck(neighbor, node, adj, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true; // Cycle detected
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // Using either BFS or DFS for cycle detection
                if (bfsCycleCheck(i, adj, visited)) return true;
                // if (dfsCycleCheck(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};

// Main function to test the cycle detection.
int main() {
    vector<vector<int>> adj1 = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    vector<vector<int>> adj2 = {{}, {2}, {1, 3}, {2}};

    Solution sol;

    cout << (sol.isCycle(adj1) ? 1 : 0) << endl; // Output: 1
    cout << (sol.isCycle(adj2) ? 0 : 0) << endl; // Output: 0

    return 0;
}
