/*You are given an integer n representing the number of rooms numbered from 0 to n - 1. Additionally, you are given a 2D integer array meetings[][] where meetings[i] = [starti, endi] indicates that a meeting is scheduled during the half-closed time interval [starti, endi). All starti values are unique.

Meeting Allocation Rules:

When a meeting starts, assign it to the available room with the smallest number.
If no rooms are free, delay the meeting until the earliest room becomes available. The delayed meeting retains its original duration.
When a room becomes free, assign it to the delayed meeting with the earliest original start time.
Determine the room number that hosts the most meetings. If multiple rooms have the same highest number of meetings, return the smallest room number among them.*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());

        // Min-heap of available rooms by room number
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        // Min-heap of occupied rooms: (endTime, roomNumber)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupiedRooms;

        // Count of meetings per room
        vector<int> meetingCount(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            // Free up rooms that are done before the current meeting's start time
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= start) {
                freeRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }

            if (!freeRooms.empty()) {
                // Assign the meeting to the smallest numbered available room
                int room = freeRooms.top();
                freeRooms.pop();
                occupiedRooms.push({end, room});
                meetingCount[room]++;
            } else {
                // Delay the meeting to the earliest room free time
                auto [freeTime, room] = occupiedRooms.top();
                occupiedRooms.pop();
                long long duration = end - start;
                occupiedRooms.push({freeTime + duration, room});
                meetingCount[room]++;
            }
        }

        // Find the room with the most meetings
        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetings || 
               (meetingCount[i] == maxMeetings && i < resultRoom)) {
                maxMeetings = meetingCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    int n1 = 2;
    vector<vector<int>> meetings1 = {{0, 6}, {2, 3}, {3, 7}, {4, 8}, {6, 8}};
    cout << "Output: " << sol.mostBooked(n1, meetings1) << endl;  // Expected: 1

    int n2 = 4;
    vector<vector<int>> meetings2 = {{0, 8}, {1, 4}, {3, 4}, {2, 3}};
    cout << "Output: " << sol.mostBooked(n2, meetings2) << endl;  // Expected: 2

    return 0;
}
