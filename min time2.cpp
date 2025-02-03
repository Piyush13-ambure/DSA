//Given an array locations[] of size n where locations[i] represents the location of the ith fruit on the x-axis and also given an array types[]  where types[i] is an integer which represents the type of the ith fruit. You are initially at coordinate 0 and you have to collect all the fruits and then return back to coordinate 0 again. To move 1 unit on the x-axis requires 1 second of time. The only condition is that you have to collect the fruits in a non-decreasing order of their types[i] (for example if ith fruit has type[i]=1 and jth fruit has type[j]=2 then ith fruit has to be picked before jth fruit). Find minimum time to collect all fruits in the non-decreasing order of their types and return back to coordinate 0.

//Note: You can assume it takes no time to pick up fruit and the location of a fruit can be negative also.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        map<int, pair<int, int>> typeBounds;
        
        // Store leftmost and rightmost positions for each type
        for (int i = 0; i < n; i++) {
            int t = types[i], loc = locations[i];
            if (typeBounds.count(t)) {
                typeBounds[t].first = min(typeBounds[t].first, loc);
                typeBounds[t].second = max(typeBounds[t].second, loc);
            } else {
                typeBounds[t] = {loc, loc};
            }
        }

        // Extract sorted types and corresponding positions
        vector<pair<int, int>> sortedTypes(typeBounds.begin(), typeBounds.end());
        int m = sortedTypes.size();

        // DP arrays: dp[i][0] => min time ending at leftmost, dp[i][1] => min time ending at rightmost
        vector<vector<long long>> dp(m, vector<long long>(2, LLONG_MAX));

        // Base case: First type, move from 0
        dp[0][0] = abs(sortedTypes[0].second - 0) + abs(sortedTypes[0].second - sortedTypes[0].first);
        dp[0][1] = abs(sortedTypes[0].first - 0) + abs(sortedTypes[0].second - sortedTypes[0].first);

        // DP Transitions
        for (int i = 1; i < m; i++) {
            int prevLeft = sortedTypes[i - 1].first, prevRight = sortedTypes[i - 1].second;
            int currLeft = sortedTypes[i].first, currRight = sortedTypes[i].second;

            // Transition from previous leftmost or rightmost position
            dp[i][0] = min(dp[i - 1][0] + abs(prevLeft - currRight),  // From left end of prev type
                           dp[i - 1][1] + abs(prevRight - currRight)) // From right end of prev type
                       + abs(currRight - currLeft);  // Move across current type's range

            dp[i][1] = min(dp[i - 1][0] + abs(prevLeft - currLeft),
                           dp[i - 1][1] + abs(prevRight - currLeft))
                       + abs(currRight - currLeft);
        }

        // Return to 0 from the last type's leftmost or rightmost position
        int lastLeft = sortedTypes[m - 1].first, lastRight = sortedTypes[m - 1].second;
        return min(dp[m - 1][0] + abs(lastLeft - 0),
                   dp[m - 1][1] + abs(lastRight - 0));
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> locations1 = {1, 3, 5, 7}, types1 = {1, 2, 3, 1};
    cout << sol.minTime(4, locations1, types1) << endl; // Output: 18

    vector<int> locations2 = {-4, -3, 1, -8}, types2 = {4, 2, 4, 5};
    cout << sol.minTime(4, locations2, types2) << endl; // Output: 24

    return 0;
}
