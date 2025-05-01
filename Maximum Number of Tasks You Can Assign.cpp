/*You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).

Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.

Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size());
        int answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }

private:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        deque<int> dq;
        int n = workers.size();
        for (int i = n - k; i < n; ++i) dq.push_back(workers[i]);  // k strongest workers

        int p = pills;

        for (int i = k - 1; i >= 0; --i) {
            if (!dq.empty() && dq.back() >= tasks[i]) {
                dq.pop_back();  // Assign task directly
            } else {
                // Try using pill on weakest worker
                while (!dq.empty() && dq.front() + strength < tasks[i]) {
                    dq.pop_front();
                }
                if (!dq.empty() && p > 0) {
                    dq.pop_front();  // Use pill
                    p--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

// Main function with test cases
int main() {
    Solution sol;

    vector<int> tasks1 = {3, 2, 1}, workers1 = {0, 3, 3};
    cout << "Example 1 Output: " << sol.maxTaskAssign(tasks1, workers1, 1, 1) << endl;

    vector<int> tasks2 = {5, 4}, workers2 = {0, 0, 0};
    cout << "Example 2 Output: " << sol.maxTaskAssign(tasks2, workers2, 1, 5) << endl;

    vector<int> tasks3 = {10, 15, 30}, workers3 = {0, 10, 10, 10, 10};
    cout << "Example 3 Output: " << sol.maxTaskAssign(tasks3, workers3, 3, 10) << endl;

    return 0;
}
