/*Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find the longest distances from s to all other vertices in the given graph. Return the distance array,  in the distance array instead of passing INF you need to have INT_MIN driver will automatically update it to INF.*/

void topo(int src,vector<int> &vis,vector<vector<pair<int,int>>> g,vector<int>& order){
    vis[src] = 1;
    // Iterating over the adjacent nodes
    for(auto x:g[src]){
        // If the node is not visited, perform topological sorting
        if(!vis[x.first])
            topo(x.first,vis,g,order);
    }
    // Pushing the current node into the order vector
    order.push_back(src);
}

class Solution
{
    public:
      // Function to find the maximum distance from a given source node to all other nodes
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {

            vector<vector<pair<int,int>>> g(v);
            // Creating the adjacency list from the given edges
            for(auto j:edges){
                g[j[0]].push_back({j[1],j[2]});
            }
            // Vector to store the order of nodes after topological sorting
            vector <int> order;
            // Vector to track visited nodes during topological sorting
            vector<int> vis(v,0);
            // Performing topological sorting on all nodes
            for(int i=0;i<v;i++){
                if(!vis[i]){
                    topo(i,vis,g,order);                    
                }                                  
            }
            // Vector to store the maximum distance from the source node to all other nodes
            vector<int> dist(v);
            // Initializing all distances as INT_MIN except for the source node
            for(int i=0;i<v;i++) dist[i] = INT_MIN;
            dist[src] = 0;
            // Iterating over the nodes in reverse topological order
            for(int i=v-1;i>=0;i--){
                // If the distance of the current node is not INT_MIN
                if(dist[order[i]]!= INT_MIN){
                    // Updating the distances of the adjacent nodes if a shorter path is found
                    for(auto x:g[order[i]]){
                        int v = dist[x.first];
                        int w = x.second;
                        int u = dist[order[i]];
                        if(u + w > v)
                            dist[x.first] = u + w;
                    }
                }
            }

            // Returning the maximum distance from the source node to all other nodes
            return dist;
      }
};
