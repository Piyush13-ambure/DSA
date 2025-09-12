/*Given a one-dimensional garden of length n. In each position of the n length garden, a sprinkler has been installed. Given an array arr[] such that arr[i] describes the coverage limit of the ith sprinkler. A sprinkler can cover the range from the position max(i - arr[i], 1) to min(i + arr[i], n). In beginning, all the sprinklers are switched off.
The task is to find the minimum number of sprinklers needed to be activated such that the whole n-length garden can be covered by water.
Note:  Array is 1-based indexed.Given a one-dimensional garden of length n. In each position of the n length garden, a sprinkler has been installed. Given an array arr[] such that arr[i] describes the coverage limit of the ith sprinkler. A sprinkler can cover the range from the position max(i - arr[i], 1) to min(i + arr[i], n). In beginning, all the sprinklers are switched off.
The task is to find the minimum number of sprinklers needed to be activated such that the whole n-length garden can be covered by water.
Note:  Array is 1-based indexed.*/

class Solution {
  public:
    // Function to find the minimum number of sprinklers needed to water all plants.
    int minSprinkler(int N, vector<int> &arr) {
        // creating a dynamic programming array of size N with initial value -1.
        vector<int> dp(N, -1);

        // iterating over all the plants.
        for (int i = 0; i < N; i++) {
            // finding the left and right boundaries for the current plant.
            int left = max(i - arr[i], 0);
            int right = min(i + arr[i] + 1, N);

            // updating the dp array with the maximum right boundary for each left
            // boundary.
            dp[left] = max(dp[left], right);
        }

        // initializing variables to keep track of sprinklers and the next right
        // boundary.
        int cn = 1, next = 0;
        int right = dp[0];

        // iterating over the dp array to count the number of sprinklers needed.
        for (int i = 0; i < N; i++) {
            // updating the next right boundary.
            next = max(next, dp[i]);

            // if the current index reaches the right boundary, increment the sprinkler
            // count and update the right boundary.
            if (i == right) {
                cn++;
                right = next;
            }
        }

        // returning the minimum number of sprinklers needed.
        return cn;
    }
};
