/*You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        // Sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // Extract the end times for binary search
        vector<int> endTimes(n);
        for (int i = 0; i < n; i++)
            endTimes[i] = events[i][1];

        // DP table: dp[i][j] = max value by considering first i events and attending at most j events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++) {
            int start = events[i - 1][0];
            int end = events[i - 1][1];
            int val = events[i - 1][2];

            // Find the last event that ends before the current event starts
            int lastNonOverlap = upper_bound(endTimes.begin(), endTimes.end(), start - 1) - endTimes.begin();

            for (int j = 1; j <= k; j++) {
                // Two choices: skip or take this event
                dp[i][j] = max(
                    dp[i - 1][j], // Don't take this event
                    dp[lastNonOverlap][j - 1] + val // Take this event
                );
            }
        }

        return dp[n][k];
    }
};

// Example main function
int main() {
    Solution sol;

    vector<vector<int>> events1 = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    int k1 = 2;
    cout << "Output: " << sol.maxValue(events1, k1) << endl; // Expected: 7

    vector<vector<int>> events2 = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    int k2 = 2;
    cout << "Output: " << sol.maxValue(events2, k2) << endl; // Expected: 10

    vector<vector<int>> events3 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
    int k3 = 3;
    cout << "Output: " << sol.maxValue(events3, k3) << endl; // Expected: 9

    return 0;
}
