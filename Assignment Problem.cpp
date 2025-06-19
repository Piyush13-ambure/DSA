/*You are the head of a firm and you have to assign jobs to people. You have N persons working under you and you have N jobs that are to be done by these persons. Each person has to do exactly one job and each job has to be done by exactly one person. Each person has his own capability (in terms of time taken) to do any particular job. Your task is to assign the jobs to the persons in such a way that the total time taken is minimum. A job can be assigned to only one person and a person can do only one job.


Your Task:
You don't need to read input or print anything. Your task is to complete the function assignmentProblem() which takes an Integer N and an array Arr[] of size N2 as input and returns the time taken for the best possible assignment.
*/


#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[1 << 20]; // Supports up to N = 20

    int solve(int person, int mask, vector<vector<int>>& cost, int N) {
        if (person == N) return 0;

        if (dp[mask] != -1) return dp[mask];

        int ans = INT_MAX;
        for (int job = 0; job < N; job++) {
            if (!(mask & (1 << job))) { // if job is not assigned
                int new_mask = mask | (1 << job);
                int current_cost = cost[person][job] + solve(person + 1, new_mask, cost, N);
                ans = min(ans, current_cost);
            }
        }
        return dp[mask] = ans;
    }

    int assignmentProblem(int Arr[], int N) {
        vector<vector<int>> cost(N, vector<int>(N));
        for (int i = 0; i < N * N; i++) {
            cost[i / N][i % N] = Arr[i];
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, cost, N);
    }
};

// ------------------ Main Function ------------------
int main() {
    Solution obj;

    // Example 1
    int Arr1[] = {3, 5, 10, 1};
    int N1 = 2;
    cout << "Output: " << obj.assignmentProblem(Arr1, N1) << endl; // Output: 4

    // Example 2
    int Arr2[] = {2, 1, 2, 9, 8, 1, 1, 1, 1};
    int N2 = 3;
    cout << "Output: " << obj.assignmentProblem(Arr2, N2) << endl; // Output: 3

    return 0;
}

