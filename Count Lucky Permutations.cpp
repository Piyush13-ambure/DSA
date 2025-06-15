/*You are given an array arr[ ] of integers having N elements and a non-weighted undirected graph having N nodes and M edges. The details of each edge in the graph is given to you in the form of list of list. 
Your task is to find the number of lucky permutations of the given array. 

An array permutation is said to be lucky if for every node Vi  [1 <= i <= N-1] in the array there exists an edge between the nodes Vi and Vi+1 in the given graph.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function luckyPermutations() which takes the two integers N and M, an array arr[ ] and a list of lists named graph of size M as input parameters and returns the count of lucky permutations.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int luckyPermutations(int N, int M, vector<int> arr, vector<vector<int>> graph) {
        // Map values to their positions in arr
        int adj[N + 1][N + 1] = {0};  // Adjacency matrix

        for (auto &edge : graph) {
            int u = edge[0];
            int v = edge[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        vector<vector<long long>> dp(1 << N, vector<long long>(N, 0));

        // Initialize base cases: single elements
        for (int i = 0; i < N; ++i) {
            dp[1 << i][i] = 1;
        }

        for (int mask = 1; mask < (1 << N); ++mask) {
            for (int u = 0; u < N; ++u) {
                if (!(mask & (1 << u))) continue;
                for (int v = 0; v < N; ++v) {
                    if (mask & (1 << v)) continue;  // v already taken
                    if (arr[u] == arr[v]) continue; // Skip same values
                    if (adj[arr[u]][arr[v]]) {
                        dp[mask | (1 << v)][v] += dp[mask][u];
                    }
                }
            }
        }

        long long res = 0;
        int fullMask = (1 << N) - 1;
        for (int i = 0; i < N; ++i) {
            res += dp[fullMask][i];
        }

        return res;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Example 1:
    int N1 = 3, M1 = 2;
    vector<int> arr1 = {1, 2, 3};
    vector<vector<int>> graph1 = {{3, 1}, {1, 2}};
    cout << "Example 1 Output: " << sol.luckyPermutations(N1, M1, arr1, graph1) << endl;

    // Example 2:
    int N2 = 2, M2 = 1;
    vector<int> arr2 = {1, 1};
    vector<vector<int>> graph2 = {{1, 2}};
    cout << "Example 2 Output: " << sol.luckyPermutations(N2, M2, arr2, graph2) << endl;

    return 0;
}
