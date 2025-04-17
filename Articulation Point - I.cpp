/*Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low,
             vector<bool>& visited, vector<bool>& isAP, int& time) {

        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!visited[v]) {
                children++;
                dfs(v, u, adj, disc, low, visited, isAP, time);
                low[u] = min(low[u], low[v]);

                // Case 1: If u is not root and low[v] >= disc[u]
                if (parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            } else {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }

        // Case 2: If u is root and has more than one child
        if (parent == -1 && children > 1)
            isAP[u] = true;
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false), isAP(V, false);
        int time = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, isAP, time);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (isAP[i]) result.push_back(i);
        }

        if (result.empty()) return {-1};

        sort(result.begin(), result.end());
        return result;
    }
};

// -------- MAIN FUNCTION --------
int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;

        // Avoid self-loops for articulation point logic
        if (u == v) continue;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> ans = obj.articulationPoints(V, adj);

    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
