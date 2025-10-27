/*Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.*/

class Solution {
  public:

    // Function to perform topological sort on a DAG
    void topoSortUtil(int v, vector<vector<int>>& adj, vector<bool>& visited,
                      stack<int>& st) {

        // Mark the current node as visited
        visited[v] = true;

        // Recur for all adjacent vertices
        for (int i : adj[v]) {
            if (!visited[i])
                topoSortUtil(i, adj, visited, st);
        }

        // Push current vertex to stack which stores the result
        st.push(v);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        // Stack to store the result
        stack<int> st;
        vector<bool> visited(V, false);

        vector<vector<int>> adj(V);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        // Call the recursive helper function to store
        // Topological Sort starting from all vertices one by
        // one
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                topoSortUtil(i, adj, visited, st);
        }

        vector<int> ans;

        // Append contents of stack
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
