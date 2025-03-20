/*There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Step 2: Find connected components using BFS/DFS
        vector<int> component(n, -1); // Stores component ID for each node
        vector<vector<int>> nodesInComponent; // Stores nodes in each component
        int compID = 0;
        
        for (int i = 0; i < n; i++) {
            if (component[i] == -1) { // Unvisited node
                queue<int> q;
                q.push(i);
                component[i] = compID;
                vector<int> nodes;
                nodes.push_back(i);
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (auto& [neighbor, w] : adj[node]) {
                        if (component[neighbor] == -1) {
                            component[neighbor] = compID;
                            q.push(neighbor);
                            nodes.push_back(neighbor);
                        }
                    }
                }
                
                nodesInComponent.push_back(nodes);
                compID++;
            }
        }

        // Step 3: Compute minimum bitwise AND cost for each connected component
        unordered_map<int, unordered_map<int, int>> minCost; // {node -> {dest -> min AND cost}}
        
        for (auto& nodes : nodesInComponent) {
            int compSize = nodes.size();
            unordered_map<int, unordered_map<int, int>> cost;
            
            for (int src : nodes) {
                queue<pair<int, int>> q;
                q.push({src, INT_MAX});
                cost[src][src] = 0; // Cost from node to itself is 0
                
                while (!q.empty()) {
                    auto [node, currCost] = q.front();
                    q.pop();
                    
                    for (auto& [neighbor, w] : adj[node]) {
                        int newCost = currCost & w;
                        if (cost[src].find(neighbor) == cost[src].end() || cost[src][neighbor] > newCost) {
                            cost[src][neighbor] = newCost;
                            q.push({neighbor, newCost});
                        }
                    }
                }
            }
            
            for (auto& [u, mp] : cost) {
                for (auto& [v, c] : mp) {
                    minCost[u][v] = c;
                }
            }
        }

        // Step 4: Answer queries
        vector<int> result;
        for (auto& q : query) {
            int si = q[0], ti = q[1];

            if (component[si] != component[ti]) {
                result.push_back(-1); // Different components, no valid walk
            } else if (si == ti) {
                result.push_back(0); // Same node, cost is 0
            } else {
                result.push_back(minCost[si][ti]); // Precomputed cost
            }
        }
        
        return result;
    }
};

// Driver function
int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1,7},{1,3,7},{1,2,1}};
    vector<vector<int>> query = {{0,3},{3,4}};

    Solution obj;
    vector<int> res = obj.minimumCost(n, edges, query);
    
    for (int ans : res) {
        cout << ans << " ";
    }
    cout << endl;
    
    return 0;
}
