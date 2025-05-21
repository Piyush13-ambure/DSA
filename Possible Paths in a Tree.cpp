/*Given a weighted tree with n nodes and (n-1) edges. You are given q queries. Each query contains a number x. For each query, find the number of paths in which the maximum edge weight is less than or equal to x.

Note: Path from A to B and B to A are considered to be the same.
Your Task:  
You don't need to read input or print anything. Complete the function maximumWeight()which takes integers n, list of edges where each edge is given by {start,end,weight}, an integer q and a list of q queries as input parameters and returns a list of integers denoting the number of possible paths for each query. */

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    long long unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return 0;
        long long paths = (long long)size[px] * size[py];
        if (size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
        return paths;
    }
};

class Solution {
public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q,
                              vector<int> &queries) {
        vector<tuple<int, int, int>> edgeList;
        for (auto &e : edges) {
            edgeList.emplace_back(e[2], e[0], e[1]);  // (weight, u, v)
        }
        sort(edgeList.begin(), edgeList.end());

        vector<pair<int, int>> queryList;  // {query, original index}
        for (int i = 0; i < q; ++i)
            queryList.emplace_back(queries[i], i);
        sort(queryList.begin(), queryList.end());

        vector<int> res(q);
        DSU dsu(n);
        int i = 0;
        long long totalPaths = 0;

        for (auto &[x, idx] : queryList) {
            while (i < edgeList.size() && get<0>(edgeList[i]) <= x) {
                totalPaths += dsu.unite(get<1>(edgeList[i]), get<2>(edgeList[i]));
                ++i;
            }
            res[idx] = totalPaths;
        }

        return res;
    }
};

// --------- Main Function --------------
int main() {
    int n, q;
    cin >> n;
    vector<vector<int>> edges(n - 1, vector<int>(3));
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    Solution sol;
    vector<int> result = sol.maximumWeight(n, edges, q, queries);

    for (int ans : result) {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}
