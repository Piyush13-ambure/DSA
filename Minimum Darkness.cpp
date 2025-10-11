/*Aryan has discovered a magical tree in a forest consisting of n enchanted villages, represented as nodes of an undirected tree — that is, a connected, acyclic graph with exactly n - 1 edges.
Each village is either:

Green — unvisited by Aryan
Red — visited by Aryan
Initially, all villages are green.
You're given an array arr of size k, which contains the sequence of k operations Aryan performs. In each operation, Aryan chooses a village from arr[i] and turns it red.
You're also given n - 1 undirected edges where each edge connects two villages u and v. These edges define the tree's structure and represent its adjacency list.
After each operation, Aryan wants to know the darkness of the red tree. The darkness is defined as the minimum number of edges between any two red villages.
If there are fewer than two red villages at any point, output -1 for that operation (since darkness is undefined).

Note: k is smaller than n and all values inside arr will be unique*/

class Solution {
  public:
    void dfs(int node, int par, vector<vector<int>>& tree, vector<int>& dis,
             vector<bool>& isclr, int& ans) {
        if (dis[node] >= ans)
            return;

        if (isclr[node]) {
            ans = min(ans, dis[node]);
        }

        for (int ch : tree[node]) {
            if (ch == par)
                continue;

            if (dis[ch] > dis[node] + 1) {
                dis[ch] = dis[node] + 1;
                dfs(ch, node, tree, dis, isclr, ans);
            } else {
                ans = min(ans, dis[node] + dis[ch] + 1);
            }
        }
    }

    vector<int> solve(int n, int k, vector<int>& query, vector<vector<int>>& edges) {
        // Step 1: Build the tree (adjacency list) from edges
        int INF = 1e7;
        vector<vector<int>> tree(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // Step 2: Solve the problem
        int ans = INF;
        vector<int> dis(n + 1, INF);
        vector<bool> isclr(n + 1, false);
        vector<int> out;

        for (int i = 0; i < k; i++) {
            int ele = query[i];
            dis[ele] = 0;
            dfs(ele, -1, tree, dis, isclr, ans);
            isclr[ele] = true;

            if (i == 0)
                out.push_back(-1);
            else
                out.push_back(ans);
        }

        return out;
    }
};
