/*You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.

You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.

The relative order of all the meetings should stay the same and they should remain non-overlapping.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event.



*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> meetingDuration(n);
        
        for (int i = 0; i < n; ++i) {
            meetingDuration[i] = endTime[i] - startTime[i];
        }

        // Create prefix and suffix arrays of gaps between meetings
        vector<int> gaps(n + 1, 0);  // gaps[i]: free time before meeting i
        gaps[0] = startTime[0] - 0;
        for (int i = 1; i < n; ++i) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }
        gaps[n] = eventTime - endTime[n - 1];

        // The initial maximum free time is the largest gap
        int maxGap = *max_element(gaps.begin(), gaps.end());

        // Try shifting meetings to maximize free time
        for (int i = 0; i < n; ++i) {
            int left = i, right = min(n, i + k); // Move up to k meetings starting from i
            // Try to shift the block of meetings [left, right-1] as far left as possible
            int newStart = (left == 0) ? 0 : endTime[left - 1]; // Can't move past previous meeting
            int newEnd = newStart;
            for (int j = left; j < right; ++j) {
                newEnd += meetingDuration[j]; // Sum up durations
            }
            int gapAfter = (right == n) ? eventTime - newEnd : startTime[right] - newEnd;
            maxGap = max(maxGap, gapAfter);
        }

        return maxGap;
    }
};

// Example usage
int main() {
    Solution obj;

    vector<int> startTime1 = {1, 3};
    vector<int> endTime1 = {2, 5};
    cout << "Example 1 Output: " << obj.maxFreeTime(5, 1, startTime1, endTime1) << endl;  // Expected: 2

    vector<int> startTime2 = {0, 2, 9};
    vector<int> endTime2 = {1, 4, 10};
    cout << "Example 2 Output: " << obj.maxFreeTime(10, 1, startTime2, endTime2) << endl;  // Expected: 6

    vector<int> startTime3 = {0, 1, 2, 3, 4};
    vector<int> endTime3 = {1, 2, 3, 4, 5};
    cout << "Example 3 Output: " << obj.maxFreeTime(5, 2, startTime3, endTime3) << endl;  // Expected: 0

    return 0;
}
