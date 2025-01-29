//In this problem, a tree is an undirected graph that is connected and has no cycles.

//You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

//Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Disjoint Set Union (DSU) with Path Compression and Union by Rank
    class DSU {
        vector<int> parent, rank;
    public:
        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                parent[i] = i; // Initialize each node as its own parent
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        bool unionSet(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) return false; // Cycle detected

            // Union by Rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (auto& edge : edges) {
            if (!dsu.unionSet(edge[0], edge[1])) {
                return edge; // Return the edge that forms a cycle
            }
        }

        return {}; // This case should never occur as per problem constraints
    }
};

// Main function to test
int main() {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    
    vector<int> result = sol.findRedundantConnection(edges);
    
    cout << "Redundant Edge: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
