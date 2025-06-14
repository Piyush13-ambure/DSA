/*Given N nodes of a tree and a list of edges. Find the minimum number of nodes to be selected to light up all the edges of the tree.
An edge lights up when at least one node at the end of the edge is selected.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countVertex() which takes the number of nodes N, and the list of edges as input parameters and returns the minimum number of nodes selected.

*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> adj[100005];
    int dp[100005][2];

    void dfs(int u, int parent) {
        dp[u][0] = 0;
        dp[u][1] = 1;

        for (int v : adj[u]) {
            if (v == parent) continue;
            dfs(v, u);
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    }

    int countVertex(int N, vector<vector<int>> edges) {
        for (int i = 0; i <= N; ++i) {
            adj[i].clear();
        }

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1); // assuming node 1 as root
        return min(dp[1][0], dp[1][1]);
    }
};

int main() {
    Solution sol;

    // Example 1:
    int N1 = 6;
    vector<vector<int>> edges1 = {{1,2}, {1,3}, {2,4}, {3,5}, {3,6}};
    cout << "Output: " << sol.countVertex(N1, edges1) << endl;

    // Example 2:
    int N2 = 3;
    vector<vector<int>> edges2 = {{1,2}, {1,3}};
    cout << "Output: " << sol.countVertex(N2, edges2) << endl;

    return 0;
}

