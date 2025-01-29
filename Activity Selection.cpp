//Given some activities with their start and end day given in array start[] and end[]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
//Note : Duration of the activity includes both starting and ending day.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &end) {
        int n = start.size();
        vector<pair<int, int>> activities;

        // Store activities as (end_time, start_time) for easy sorting
        for (int i = 0; i < n; i++) {
            activities.push_back({end[i], start[i]});
        }

        // Sort by end time (Greedy choice)
        sort(activities.begin(), activities.end());

        int count = 1;  // First activity is always selected
        int last_end_time = activities[0].first;

        // Select remaining activities
        for (int i = 1; i < n; i++) {
            if (activities[i].second > last_end_time) { // If start time is after last selected end time
                count++;
                last_end_time = activities[i].first;
            }
        }

        return count;
    }
};

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<int> start(n), end(n);
    cout << "Enter start times: ";
    for (int i = 0; i < n; i++) cin >> start[i];

    cout << "Enter end times: ";
    for (int i = 0; i < n; i++) cin >> end[i];

    Solution sol;
    cout << "Maximum number of activities: " << sol.activitySelection(start, end) << endl;

    return 0;
}
