/*There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.

Note: If two meetings can be chosen for the same slot then choose meeting that finishes earlier.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        // Store meetings as {finish_time, start_time, index}
        vector<tuple<int, int, int>> meetings;
        for (int i = 0; i < N; i++) {
            meetings.push_back({F[i], S[i], i + 1});  // Store index as 1-based
        }

        // Sort by finish time (ascending order)
        sort(meetings.begin(), meetings.end());

        vector<int> result;
        int last_end_time = -1;

        // Select meetings greedily
        for (auto &[finish, start, index] : meetings) {
            if (start > last_end_time) {
                result.push_back(index);
                last_end_time = finish;
            }
        }

        // Return meeting numbers in sorted order
        sort(result.begin(), result.end());
        return result;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> S(N), F(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> F[i];
        }
        Solution obj;
        vector<int> ans = obj.maxMeetings(N, S, F);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i != ans.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
