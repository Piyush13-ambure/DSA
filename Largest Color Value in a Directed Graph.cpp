/*There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        // Build the graph and in-degree
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        // Initialize count array
        vector<vector<int>> count(n, vector<int>(26, 0));
        queue<int> q;

        // Start with nodes having 0 in-degree
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        int maxColorValue = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            int colorIdx = colors[node] - 'a';
            count[node][colorIdx]++;
            maxColorValue = max(maxColorValue, count[node][colorIdx]);

            for (int neighbor : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    count[neighbor][c] = max(count[neighbor][c], count[node][c]);
                }
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If cycle exists
        if (visited != n) return -1;

        return maxColorValue;
    }
};

// Example driver
int main() {
    Solution sol;

    // Example 1
    string colors1 = "abaca";
    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{3,4}};
    cout << "Example 1 Output: " << sol.largestPathValue(colors1, edges1) << endl;

    // Example 2
    string colors2 = "a";
    vector<vector<int>> edges2 = {{0,0}};
    cout << "Example 2 Output: " << sol.largestPathValue(colors2, edges2) << endl;

    return 0;
}
