/*You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

*/


#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].emplace_back(v, time);
            adj[v].emplace_back(u, time);
        }

        // Min-heap to store {time, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);

        // Distance and ways arrays
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [cur_time, node] = pq.top();
            pq.pop();

            if (cur_time > dist[node]) continue; // Skip outdated paths

            for (auto [neighbor, travel_time] : adj[node]) {
                long long new_time = cur_time + travel_time;

                if (new_time < dist[neighbor]) { 
                    // Found a shorter path
                    dist[neighbor] = new_time;
                    ways[neighbor] = ways[node];
                    pq.emplace(new_time, neighbor);
                } 
                else if (new_time == dist[neighbor]) { 
                    // Found another shortest path
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};

int main() {
    vector<vector<int>> roads = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
        {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}
    };
    int n = 7;

    Solution sol;
    cout << "Number of ways: " << sol.countPaths(n, roads) << endl;
    
    return 0;
}
