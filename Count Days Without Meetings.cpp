/*You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        unordered_set<int> meetingDays;

        // Mark all meeting days
        for (const auto& meeting : meetings) {
            for (int d = meeting[0]; d <= meeting[1]; d++) {
                meetingDays.insert(d);
            }
        }

        // Count free days
        return days - meetingDays.size();
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    // Test case 1
    int days1 = 10;
    vector<vector<int>> meetings1 = {{5,7},{1,3},{9,10}};
    cout << sol.countDays(days1, meetings1) << endl; // Output: 2

    // Test case 2
    int days2 = 5;
    vector<vector<int>> meetings2 = {{2,4},{1,3}};
    cout << sol.countDays(days2, meetings2) << endl; // Output: 1

    // Test case 3
    int days3 = 6;
    vector<vector<int>> meetings3 = {{1,6}};
    cout << sol.countDays(days3, meetings3) << endl; // Output: 0

    return 0;
}
