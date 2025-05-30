/*You are given an n x n binary matrix grid[][]. You are allowed to change at most one 0 to 1. A group of connected 1s forms an island. Two 1s are connected if they share one of their sides with each other.

Return the size of the largest island in the grid after applying this operation.*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1) return 0;
        grid[i][j]=index;
        int count = dfs(grid, i+1, j, index) + 
                    dfs(grid, i-1, j, index) + 
                    dfs(grid, i, j+1, index) + 
                    dfs(grid, i, j-1, index);
        return count+1;
    }
    
    void findNeighbours(vector<vector<int>>& grid, int i, int j, set<int>& s) {
		//finding adjacent island groups
        int n=grid.size();
        if(i>0) s.insert(grid[i-1][j]);
        if(j>0) s.insert(grid[i][j-1]);
        if(i<n-1) s.insert(grid[i+1][j]);
        if(j<n-1) s.insert(grid[i][j+1]);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(), res=0, index=2, count;
        map<int, int> area;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    area[index]=dfs(grid, i, j, index);
                    res=max(res, area[index++]);
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    set<int> s;
                    findNeighbours(grid, i, j, s);
                    count=1;   
                    for(int i:s)
                        count+=area[i];     
                    res=max(res, count);
                }
            }
        }
        
        return res;
    }
};


int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

 }
