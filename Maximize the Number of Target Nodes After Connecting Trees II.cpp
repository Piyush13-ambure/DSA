/*There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency list for both trees
        vector<vector<int>> tree1(n), tree2(m);
        for (auto& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }

        // Step 1: Count even and odd depth nodes in Tree2 using BFS
        vector<int> depth2(m, -1);
        queue<int> q;
        q.push(0);
        depth2[0] = 0;

        int evenCount = 1, oddCount = 0;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int neighbor : tree2[curr]) {
                if (depth2[neighbor] == -1) {
                    depth2[neighbor] = depth2[curr] + 1;
                    if (depth2[neighbor] % 2 == 0) evenCount++;
                    else oddCount++;
                    q.push(neighbor);
                }
            }
        }

        // Step 2: Compute depth for all nodes in Tree1
        vector<int> depth1(n, -1);
        q.push(0);
        depth1[0] = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int neighbor : tree1[curr]) {
                if (depth1[neighbor] == -1) {
                    depth1[neighbor] = depth1[curr] + 1;
                    q.push(neighbor);
                }
            }
        }

        // Step 3: For each node in Tree1, use depth parity to choose max targets
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            if (depth1[i] % 2 == 0) result[i] = evenCount;
            else result[i] = oddCount;
        }
        return result;
    }
};

// ---------- Main Function ----------
int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};

    vector<int> result = sol.maxTargetNodes(edges1, edges2);
    for (int x : result) cout << x << " ";
    cout << endl;

    // Expected Output: 8 7 7 8 8

    vector<vector<int>> edges1b = {{0,1},{0,2},{0,3},{0,4}};
    vector<vector<int>> edges2b = {{0,1},{1,2},{2,3}};
    result = sol.maxTargetNodes(edges1b, edges2b);
    for (int x : result) cout << x << " ";
    cout << endl;

    // Expected Output: 3 6 6 6 6

    return 0;
}
