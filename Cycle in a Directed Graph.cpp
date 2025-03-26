/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isCyclic(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> inDegree(V, 0);
        
        // Compute in-degrees of all nodes
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }
        
        queue<int> q;
        // Push nodes with 0 in-degree into the queue
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // Count of visited nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If count of processed nodes is less than V, there's a cycle
        return count != V;
    }
};

int main() {
    Solution sol;
    int V = 4;
    vector<vector<int>> adj = {{1}, {2}, {3}, {1}};  // Graph with cycle: 1 → 2 → 3 → 1
    
    cout << sol.isCyclic(adj) << endl; // Output: 1 (true)
    
    vector<vector<int>> adj2 = {{1}, {2}, {3}, {}};  // Acyclic Graph
    cout << sol.isCyclic(adj2) << endl; // Output: 0 (false)

    return 0;
}
