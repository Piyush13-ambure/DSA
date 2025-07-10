/*You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, each of length n.

These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most one meeting by moving its start time while maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.

Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting.

 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        // Calculate original gaps between the meetings
        vector<int> gaps;
        gaps.push_back(startTime[0]); // Before the first meeting
        for (int i = 1; i < n; i++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[n - 1]); // After the last meeting

        // Calculate the maximum free time without any changes
        int maxFree = *max_element(gaps.begin(), gaps.end());

        // Total occupied time for each interval
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++) {
            intervals.push_back({startTime[i], endTime[i]});
        }

        // Try rescheduling each meeting
        for (int i = 0; i < n; i++) {
            // Remove meeting i
            vector<pair<int, int>> temp;
            for (int j = 0; j < n; j++) {
                if (j != i)
                    temp.push_back(intervals[j]);
            }

            // Sort the remaining intervals
            sort(temp.begin(), temp.end());

            // Calculate available gaps
            vector<pair<int, int>> freeIntervals;

            if (temp.size() == 0) {
                freeIntervals.push_back({0, eventTime});
            } else {
                if (temp[0].first > 0)
                    freeIntervals.push_back({0, temp[0].first});
                for (int k = 1; k < temp.size(); k++) {
                    if (temp[k - 1].second < temp[k].first)
                        freeIntervals.push_back({temp[k - 1].second, temp[k].first});
                }
                if (temp[temp.size() - 1].second < eventTime)
                    freeIntervals.push_back({temp[temp.size() - 1].second, eventTime});
            }

            int duration = endTime[i] - startTime[i];

            for (auto &free : freeIntervals) {
                if (free.second - free.first >= duration) {
                    // Fit meeting here
                    int leftFree = free.first - 0;
                    int rightFree = eventTime - free.second;
                    int betweenFree = 0;

                    vector<pair<int, int>> merged = temp;
                    merged.push_back({free.first, free.first + duration});
                    sort(merged.begin(), merged.end());

                    // Find max free time with this arrangement
                    int prev = 0;
                    for (auto &p : merged) {
                        betweenFree = max(betweenFree, p.first - prev);
                        prev = p.second;
                    }
                    betweenFree = max(betweenFree, eventTime - prev);

                    maxFree = max(maxFree, betweenFree);
                }
            }
        }

        return maxFree;
    }
};

// Example main function
int main() {
    Solution sol;

    int eventTime1 = 5;
    vector<int> startTime1 = {1, 3};
    vector<int> endTime1 = {2, 5};
    cout << sol.maxFreeTime(eventTime1, startTime1, endTime1) << endl;  // Output: 2

    int eventTime2 = 10;
    vector<int> startTime2 = {0, 7, 9};
    vector<int> endTime2 = {1, 8, 10};
    cout << sol.maxFreeTime(eventTime2, startTime2, endTime2) << endl;  // Output: 7

    int eventTime3 = 10;
    vector<int> startTime3 = {0, 3, 7, 9};
    vector<int> endTime3 = {1, 4, 8, 10};
    cout << sol.maxFreeTime(eventTime3, startTime3, endTime3) << endl;  // Output: 6

    int eventTime4 = 5;
    vector<int> startTime4 = {0, 1, 2, 3, 4};
    vector<int> endTime4 = {1, 2, 3, 4, 5};
    cout << sol.maxFreeTime(eventTime4, startTime4, endTime4) << endl;  // Output: 0

    return 0;
}
