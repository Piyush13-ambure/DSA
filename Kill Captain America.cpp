/*Captain America is hiding from Thanos in a maze full of n rooms connected by m gates. The maze is designed in such a way that each room leads to another room via gates. All connecting gates are unidirectional. Captain America is hiding only in those rooms which are accessible directly/indirectly through every other room in the maze.
Help Thanos find the number of rooms in which Captain America can hide. 

*/

class Solution {
    static const int MAXN = 40000;
    vector<vector<int>> graph, graphT;
    vector<int> sol;
    vector<bool> visited;
    vector<int> conne, in;

    void dfs1(int S) {
        visited[S] = true;
        for (int i = 0; i < graph[S].size(); ++i) {
            if (!visited[graph[S][i]]) {
                dfs1(graph[S][i]);
            }
        }
        sol.push_back(S);
    }

    void dfs2(int S, int c) {
        visited[S] = false;
        conne[S] = c;
        for (int i = 0; i < graphT[S].size(); ++i) {
            if (visited[graphT[S][i]]) {
                dfs2(graphT[S][i], c);
            }
        }
    }

  public:
    int captainAmerica(int n, vector<vector<int>>& gates) {
        int m = gates.size();
        sol.clear();
        graph.assign(MAXN + 1, vector<int>());
        graphT.assign(MAXN + 1, vector<int>());
        visited.assign(MAXN + 1, false);
        conne.assign(MAXN + 1, 0);
        in.assign(MAXN + 1, 0);

        // Build the graph and its transpose
        for (int i = 0; i < m; ++i) {
            int u = gates[i][0];
            int v = gates[i][1];
            graph[v].push_back(u);
            graphT[u].push_back(v);
        }

        // Perform the first DFS to fill the order
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                dfs1(i);
            }
        }

        // Perform the second DFS to assign components
        int compon = 0;
        for (int i = sol.size() - 1; i >= 0; --i) {
            if (visited[sol[i]]) {
                dfs2(sol[i], compon++);
            }
        }

        // Count the in-degrees of each component
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                if (conne[i] != conne[graph[i][j]]) {
                    in[conne[graph[i][j]]]++;
                }
            }
        }

        // Count the number of components with no incoming edges
        int ou = 0;
        for (int i = 0; i < compon; ++i) {
            if (in[i] == 0) {
                ++ou;
            }
        }

        if (ou > 1) {
            return 0;
        } else {
            ou = 0;
            for (int i = 1; i <= n; ++i) {
                if (in[conne[i]] == 0) {
                    ++ou;
                }
            }
            return ou;
        }
    }
};
