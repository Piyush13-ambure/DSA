/*You are given an array of intervals arr[][], where each interval is represented by two integers [start, end] (inclusive). Return the maximum number of intervals that overlap at any point in time.*/




class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        int maxi = -1;

        // Find the max value occurring
        // inside the intervals
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, max(arr[i][0], arr[i][1]));
        }

        // Construct a difference array
        vector<int> v(maxi + 1, 0);
        for (int i = 0; i < arr.size(); i++) {

            // v[l] will be incremented by 1
            v[arr[i][0]] += 1;
            if (arr[i][1] < maxi) {
                v[arr[i][1] + 1] -= 1;
            }
        }

        // Prefix sum
        for (int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }
        return *max_element(v.begin(), v.end());
    }
};
