/*You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array of integers nums consisting of elements ranging from l to r, both inclusive.

In one operation, you can:

Select two integers a and b from the array.
Replace them with floor(a / 4) and floor(b / 4).
Your task is to determine the minimum number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.*/


class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long S = 0;
            int dMax = 0;

            for (int k = 1; k <= 31; k++) {
                long long low = 1LL << (k - 1);
                long long high = (1LL << k) - 1;
                if (low > r) break;
                long long a = max((long long)l, low);
                long long b = min((long long)r, high);
                if (a > b) continue;
                long long cnt = b - a + 1;
                int stepsForK = (k + 1) / 2;
                S += cnt * stepsForK;
                dMax = max(dMax, stepsForK);
            }

            long long ops = max((long long)dMax, (S + 1) / 2);
            ans += ops;
        }
        return ans;
    }
};
