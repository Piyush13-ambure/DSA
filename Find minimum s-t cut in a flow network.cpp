/*Given a weighted graph of N vertices numbered from 0 to N-1 in the form of adjacency matrix A[ ][ ] and two integers S denoting the number of source vertex and T denoting the number of sink vertex. The task is to find minimum capacity s-t cut of the given network. An s-t cut is a cut that requires the source node ‘S’ and the sink node ‘T’ to be in different subsets, and it consists of edges going from the source’s side to the sink’s side. The capacity of an s-t cut is defined by the sum of the capacity of each edge in the cut-set. In other words, you have to find out all the edges which has to be removed to make it impossible to reach the sink node from source node, and the edges you select should have a minimum sum of weights. You have to return all the edges included in the minimum capacity s-t cut and if there are no edges in minimum capacity s-t cut, return "-1".

Your Task: 
You don't need to read input or print anything. Your task is to complete the function minimumCut() which takes the adjacency matrix A[ ][ ], source node number S, sink node number T and number of vertices N and returns a list of integers res[ ] where res[2*i-1] and res[2*i] denotes an edge in minimum capacity s-t cut where 1 ≤ i ≤ length(res)/2, if there are no edges in minimum capacity s-t cut, return only one integer "-1" in res[ ].
*/



int bfs(vector<vector<int>> &rGraph, int s, int t, int N, vector<int> &parent) 
{ 
    // Create a visited array and mark all vertices as not visited 
    vector<bool> visited(N); 
  
    // Create a queue, enqueue source vertex and mark source vertex 
    // as visited 
    queue<int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    // Standard BFS Loop 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int v=0; v<N; v++) 
        { 
            if (visited[v]==false && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
  
    // If we reached sink in BFS starting from source, then return 
    // true, else false 
    return (visited[t] == true); 
} 

// A DFS based function to find all reachable vertices from s.  The function 
// marks visited[i] as true if i is reachable from s.  The initial values in 
// visited[] must be false. We can also use BFS to find reachable vertices 
void dfs(vector<vector<int>> &rGraph, int S, int N, vector<bool> &visited) 
{ 
    visited[S] = true; 
    for (int i = 0; i < N; i++) 
       if (rGraph[S][i] && !visited[i]) 
           dfs(rGraph, i, N, visited); 
} 

vector<int> minimumCut(vector<vector<int>> &A, int S, int T, int N){
    int u, v; 
  
    // Create a residual graph and fill the residual graph with 
    // given capacities in the original graph as residual capacities 
    // in residual graph 
    vector<vector<int>> rGraph;
    rGraph = A;
  
    vector<int> parent(N);  // This array is filled by BFS and to store path 
    
    // Augment the flow while there is a path from source to sink 
    while (bfs(rGraph, S, T, N, parent)) 
    { 
        // Find minimum residual capacity of the edhes along the 
        // path filled by BFS. Or we can say find the maximum flow 
        // through the path found. 
        int path_flow = INT_MAX; 
        for (v=T; v!=S; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
  
        // update residual capacities of the edges and reverse edges 
        // along the path 
        for (v=T; v != S; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
    } 
  
    // Flow is maximum now, find vertices reachable from s 
    vector<bool> visited(N); 
    dfs(rGraph, S, N, visited); 
    
    vector<int> res;
  
    // Returning all edges that are from a reachable vertex to 
    // non-reachable vertex in the original graph 
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < N; j++) 
         if (visited[i] && !visited[j] && A[i][j]) {
             res.push_back(i);
             res.push_back(j);
         }
    if(res.size()==0){
        res.push_back(-1);
    }
    return res; 
}
