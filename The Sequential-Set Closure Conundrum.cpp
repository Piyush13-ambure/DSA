/*Let U = {1, 2, ..., n} be a totally ordered universe. Initially, each element of U stands in isolation. We then enact m closure operations, indexed 1 through m.

Operation t is specified by a  triple (at, dt, kt), where: 1 ≤ at,  1 ≤ dt ≤ 10,  kt ≥ 0,  at + dt × kt ≤ n.
From this triple we form the arithmetic chain: At = {at, at + dt, at + 2dt, ..., at + kt×dt } ⊆ U.
The operation then closes At under pairwise adjacency: for every x, y ∈ At we assert a bidirectional link between x and y.
At the end of all m operations, the universe U is partitioned into equivalence classes via the transitive closure of these links. Your task is to determine the final count of such classes.

*/

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class DisJointSet {
  public:
    vector<int> size, parent, rank;
    int components;

    DisJointSet(int n) {
        components = n;
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        components--;
    }
};

class Solution {
  public:
    int findComponents(int n, int m, const vector<vector<int>>& arr) {
        vector<vector<int>> res(n + 1, vector<int>(11, 0));

        for (int i = 0; i < m; ++i) {
            int a = arr[i][0], d = arr[i][1], k = arr[i][2];
            res[a][d] = max(res[a][d], k);
        }

        DisJointSet ds(n);

        for (int d = 1; d <= 10; ++d) {
            for (int i = 1; i <= n; ++i) {
                int iter = res[i][d];
                int start = i;

                while (iter > 0 && start + d <= n) {
                    ds.unionBySize(start, start + d);
                    res[start][d] = 0;
                    start += d;
                    iter = max(iter - 1, res[start][d]);
                }
            }
        }

        return ds.components;
    }
};
