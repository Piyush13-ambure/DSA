/*You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    void traverse(const vector<int>& edges, int start, vector<int>& dist) {
        int n = edges.size();
        vector<bool> visited(n, false);
        int d = 0;
        while (start != -1 && !visited[start]) {
            dist[start] = d;
            visited[start] = true;
            start = edges[start];
            d++;
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        traverse(edges, node1, dist1);
        traverse(edges, node2, dist2);

        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};

// Main function for testing
int main() {
    Solution sol;

    vector<int> edges1 = {2, 2, 3, -1};
    int node1_1 = 0, node2_1 = 1;
    cout << "Output 1: " << sol.closestMeetingNode(edges1, node1_1, node2_1) << endl; // Expected: 2

    vector<int> edges2 = {1, 2, -1};
    int node1_2 = 0, node2_2 = 2;
    cout << "Output 2: " << sol.closestMeetingNode(edges2, node1_2, node2_2) << endl; // Expected: 2

    return 0;
}
