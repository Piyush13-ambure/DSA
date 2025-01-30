//You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

//You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

//Divide the nodes of the graph into m groups (1-indexed) such that:

//Each node in the graph belongs to exactly one group.
//For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.///Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        
        // Step 1: Build Adjacency List
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0); // 0: unvisited, 1: color 1, -1: color 2
        vector<bool> visited(n + 1, false);

        int maxGroups = 0;

        // Step 2 & 3: Traverse Each Component
        for (int node = 1; node <= n; node++) {
            if (visited[node]) continue;

            vector<int> component;
            queue<int> q;
            q.push(node);
            color[node] = 1; // Start with color 1
            component.push_back(node);
            visited[node] = true;

            // BFS to check bipartiteness and collect component nodes
            bool isBipartite = true;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int neighbor : adj[cur]) {
                    if (color[neighbor] == 0) { // Not visited
                        color[neighbor] = -color[cur]; // Assign opposite color
                        q.push(neighbor);
                        visited[neighbor] = true;
                        component.push_back(neighbor);
                    } else if (color[neighbor] == color[cur]) {
                        // Conflict in bipartiteness
                        return -1;
                    }
                }
            }

            // Step 4: Find the longest shortest path (Max BFS depth)
            int maxDepth = 0;
            for (int startNode : component) {
                maxDepth = max(maxDepth, bfsDepth(startNode, adj, n));
            }
            
            maxGroups += maxDepth;
        }

        return maxGroups;
    }

    // BFS to determine the max depth from a starting node
    int bfsDepth(int start, vector<vector<int>>& adj, int n) {
        vector<int> depth(n + 1, -1);
        queue<int> q;
        q.push(start);
        depth[start] = 1;
        int maxDepth = 1;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int neighbor : adj[cur]) {
                if (depth[neighbor] == -1) {
                    depth[neighbor] = depth[cur] + 1;
                    q.push(neighbor);
                    maxDepth = max(maxDepth, depth[neighbor]);
                }
            }
        }
        return maxDepth;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 5}};
    int n = 5;
    cout << "Max Groups: " << sol.magnificentSets(n, edges) << endl;
    return 0;
}
