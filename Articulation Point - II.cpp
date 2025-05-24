/*You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v.
Your task is to return all the articulation points (or cut vertices) in the graph.
An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.

Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
If no such point exists, return {-1}.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<bool>& visited, vector<bool>& isAP, int& time) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                dfs(v, u, adj, disc, low, visited, isAP, time);
                low[u] = min(low[u], low[v]);

                // Articulation Point condition
                if (parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }
            else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // Special case for root
        if (parent == -1 && children > 1)
            isAP[u] = true;
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false), isAP(V, false);
        int time = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i])
                dfs(i, -1, adj, disc, low, visited, isAP, time);
        }

        vector<int> result;
        for (int i = 0; i < V; ++i)
            if (isAP[i])
                result.push_back(i);

        if (result.empty())
            return { -1 };
        return result;
    }
};

// Sample main function to test the solution
int main() {
    Solution sol;
    
    int V1 = 5;
    vector<vector<int>> edges1 = {{0, 1}, {1, 4}, {4, 3}, {4, 2}, {2, 3}};
    vector<int> result1 = sol.articulationPoints(V1, edges1);
    cout << "Articulation Points: ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    int V2 = 4;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}};
    vector<int> result2 = sol.articulationPoints(V2, edges2);
    cout << "Articulation Points: ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}
