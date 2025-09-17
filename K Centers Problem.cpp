/*You have given N cities numbered from 0 to N-1. The distance between each pair of cities is given by N * N matrix MAT where MAT[i][j] denotes the distance between city i and j.

The task is to select K (K<= N) ATM servers  in such a way that the maximum distance of a city from the ATM Server is minimized.*/
class Solution{
  public:
  void kCenterHelper(int k, int n, int &result, vector<int> &selected, vector<vector<int>> &mat)
    {
        if (k == 0)
        {
            // Find maximum distance of city from server.
            int maxDist = 0;
            for (int i = 0; i < n; i++)
            {
                int minDistServer = INT_MAX;
                for (int j = 0; j < selected.size(); j++)
                {
                    minDistServer = min(minDistServer, mat[i][selected[j]]);
                }
                maxDist = max(maxDist, minDistServer);
            }
            result = min(result, maxDist);
        }
        else
        {
            int prev = (selected.size() > 0) ? selected.back() : -1;
            for (int i = prev + 1; i < n; i++)
            {
                selected.push_back(i);
                
                // Recursively find ways of selecting remaining cities.
                kCenterHelper(k - 1, n, result, selected, mat);
                
                // Backtrack to explore possible way of selection without city 'i'.
                selected.pop_back();
            }
        }
    }
    
    int selectKcities(int n, int k, vector<vector<int>> &mat)
    {
        vector<int> selected;
        int result = INT_MAX;
       
        // Recursively try all possible way of selecting 'K' cities.
        kCenterHelper(k, n, result, selected, mat);
        
        return result;
    }
};
