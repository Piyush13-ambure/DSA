//Given an array locations[] of size n where locations[i] represents the location of the ith fruit on the x-axis and also given an array types[]  where types[i] is an integer which represents the type of the ith fruit. You are initially at coordinate 0 and you have to collect all the fruits and then return back to coordinate 0 again. To move 1 unit on the x-axis requires 1 second of time. The only condition is that you have to collect the fruits in a non-decreasing order of their types[i] (for example if ith fruit has type[i]=1 and jth fruit has type[j]=2 then ith fruit has to be picked before jth fruit). Find minimum time to collect all fruits in the non-decreasing order of their types and return back to coordinate 0.
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        // Step 1: Group fruits by type and find the range for each type
        map<int, pair<int, int>> typeRange;
        for (int i = 0; i < n; i++) {
            int type = types[i];
            int location = locations[i];
            if (typeRange.find(type) == typeRange.end()) {
                typeRange[type] = {location, location};
            } else {
                typeRange[type].first = min(typeRange[type].first, location);
                typeRange[type].second = max(typeRange[type].second, location);
            }
        }

        // Step 2: Extract the sorted types and their ranges
        vector<pair<int, int>> ranges;
        for (auto it = typeRange.begin(); it != typeRange.end(); ++it) {
            ranges.push_back(it->second);
        }

        // Step 3: Initialize DP arrays
        int m = ranges.size();
        vector<vector<long long>> dp(m, vector<long long>(2, LLONG_MAX));

        // Base case: Collect the first type and return to 0
        dp[0][0] = 2 * abs(ranges[0].first); // Start at 0, go to minLocation, return to 0
        dp[0][1] = 2 * abs(ranges[0].second); // Start at 0, go to maxLocation, return to 0

        // Step 4: DP transition
        for (int i = 1; i < m; i++) {
            // Transition from the previous type's min/max location
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + abs(ranges[i - 1].first - ranges[i].second) + (ranges[i].second - ranges[i].first));
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + abs(ranges[i - 1].second - ranges[i].second) + (ranges[i].second - ranges[i].first));

            dp[i][1] = min(dp[i][1], dp[i - 1][0] + abs(ranges[i - 1].first - ranges[i].first) + (ranges[i].second - ranges[i].first));
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + abs(ranges[i - 1].second - ranges[i].first) + (ranges[i].second - ranges[i].first));
        }

        // Step 5: Return the minimum time to collect all fruits and return to 0
        return min(dp[m - 1][0] + abs(ranges[m - 1].first), dp[m - 1][1] + abs(ranges[m - 1].second));
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    vector<int> locations = {1, 5, 6, 3};
    vector<int> types = {1, 2, 2, 1};
    int n = locations.size();

    cout << "Minimum time to collect all fruits: " << solution.minTime(n, locations, types) << endl;

    return 0;
}
