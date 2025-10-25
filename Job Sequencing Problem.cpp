/*You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
*/
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<int> ans = {0, 0};
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({deadline[i], profit[i]});
        }

        // sort the jobs based on deadline
        // in ascending order
        sort(jobs.begin(), jobs.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        for (const auto &job : jobs) {

            // if job can be scheduled within its deadline
            if (job.first > pq.size())
                pq.push(job.second);

            // Replace the job with the lowest profit
            else if (!pq.empty() && pq.top() < job.second) {
                pq.pop();
                pq.push(job.second);
            }
        }

        while (!pq.empty()) {
            ans[1] += pq.top();
            pq.pop();
            ans[0]++;
        }

        return ans;
    }
};
