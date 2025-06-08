/*Given an undirected connected graph of n vertices and list of m edges in a graph and for each pair of vertices that are connected by an edge. 

There are two edges between them, one curved edge and one straight edge i.e. the tuple (x, y, w1, w2) means that between vertices x and y, there is a straight edge with weight w1 and a curved edge with weight w2.

You are given two vertices a and b and you have to go from a to b through a series of edges such that in the entire path you can use at most 1 curved edge. Your task is to find the shortest path from a to b satisfying the above condition. If there is no path from a to b, return -1.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function shortestPath() which takes 4 integers n, m, a, and b, and a list of lists named edges of size m as input and returns the cost of shortest path from a to b.


*/


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<long long> dijkstra(int start, int n, vector<pair<int, int>> adj[]) {
        vector<long long> dist(n + 1, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        vector<pair<int, int>> adj[n + 1];

        // Only add straight edges for Dijkstra
        for (auto &e : edges) {
            int u = e[0], v = e[1], w1 = e[2];
            adj[u].push_back({v, w1});
            adj[v].push_back({u, w1});
        }

        vector<long long> distFromA = dijkstra(a, n, adj);
        vector<long long> distFromB = dijkstra(b, n, adj);

        long long ans = distFromA[b];  // without using curved edge

        for (auto &e : edges) {
            int u = e[0], v = e[1], w2 = e[3];

            if (distFromA[u] != LLONG_MAX && distFromB[v] != LLONG_MAX) {
                ans = min(ans, distFromA[u] + w2 + distFromB[v]);
            }
            if (distFromA[v] != LLONG_MAX && distFromB[u] != LLONG_MAX) {
                ans = min(ans, distFromA[v] + w2 + distFromB[u]);
            }
        }

        return (ans == LLONG_MAX ? -1 : (int)ans);
    }
};

// ------------------- Main Function -------------------
int main() {
    Solution sol;
    int n = 4, m = 4, a = 2, b = 4;
    vector<vector<int>> edges = {
        {1, 2, 1, 4},
        {1, 3, 2, 4},
        {1, 4, 3, 1},
        {2, 4, 6, 5}
    };

    cout << "Shortest Path: " << sol.shortestPath(n, m, a, b, edges) << endl;
    return 0;
}
