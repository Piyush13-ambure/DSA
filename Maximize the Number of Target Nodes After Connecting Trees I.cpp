/*There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.

Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    // Returns vector<int> of distances from source node
    vector<int> bfs(const vector<vector<int>>& graph, int src) {
        int n = graph.size();
        vector<int> dist(n, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : graph[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> tree1(n), tree2(m);
        for (auto& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }

        vector<vector<int>> dist1(n), dist2(m);
        for (int i = 0; i < n; ++i)
            dist1[i] = bfs(tree1, i);
        for (int j = 0; j < m; ++j)
            dist2[j] = bfs(tree2, j);

        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            int max_count = 0;
            for (int j = 0; j < m; ++j) {
                int count = 0;
                for (int u = 0; u < n; ++u)
                    if (dist1[i][u] <= k) count++;
                for (int v = 0; v < m; ++v)
                    if (dist2[j][v] <= k - 1) count++;
                max_count = max(max_count, count);
            }
            result[i] = max_count;
        }

        return result;
    }
};

// For testing
int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;

    vector<int> res = sol.maxTargetNodes(edges1, edges2, k);
    for (int val : res) cout << val << " ";
    cout << endl;

    return 0;
}

