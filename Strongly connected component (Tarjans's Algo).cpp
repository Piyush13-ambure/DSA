/*Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.

Note - Sort both the individual components and array of the components.
Your Task:
You don't need to read input or print anything. Your task is to complete the function tarjans() which takes the number of vertices V and adjacency list of the graph as input parameters and returns a list of list of integers denoting the members of strongly connected components in the given graph.
Note: A single strongly connected component must be represented in the form of a list if integers sorted in the ascending order. The resulting list should consist of a list of all SCCs which must be sorted in a way such that a lexicographically smaller list of integers appears first.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int timer;
    vector<int> tin, low;
    stack<int> st;
    vector<bool> onStack;
    vector<vector<int>> sccs;

    void dfs(int u, vector<int> adj[]) {
        tin[u] = low[u] = timer++;
        st.push(u);
        onStack[u] = true;

        for (int v : adj[u]) {
            if (tin[v] == -1) {
                dfs(v, adj);
                low[u] = min(low[u], low[v]);
            } else if (onStack[v]) {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (tin[u] == low[u]) {
            vector<int> scc;
            while (true) {
                int v = st.top(); st.pop();
                onStack[v] = false;
                scc.push_back(v);
                if (v == u) break;
            }
            sort(scc.begin(), scc.end());
            sccs.push_back(scc);
        }
    }

public:
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        timer = 0;
        tin.assign(V, -1);
        low.assign(V, -1);
        onStack.assign(V, false);

        for (int i = 0; i < V; ++i) {
            if (tin[i] == -1) {
                dfs(i, adj);
            }
        }

        sort(sccs.begin(), sccs.end());
        return sccs;
    }
};

// ---------- Sample Main Function ----------
int main() {
    int V = 5; // Example 1: change as needed
    vector<int> adj[V];

    // Sample edges: creating a graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    Solution obj;
    vector<vector<int>> result = obj.tarjans(V, adj);

    // Output result
    for (const auto& comp : result) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
