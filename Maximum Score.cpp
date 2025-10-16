/*You are given an array arr[] of positive integers of size n and your initial score x. Now, for every subarray for size 1 to n, compute the sum of medians of all subarrays of that size. You are given one chance to improve your score.
In this, you must choose exactly k values from the computed median sums, perform a bitwise AND operation on them, and then perform a bitwise OR between the result and your initial score x.
Return the maximum possible score you can achieve after performing this operation.

*/

class Solution {
  public:
    int median_sum(vector<int>& arr, int n, int k) {
        int sum = 0;
        int p = (k + 1) / 2; // size of ms1 (lower half)

        multiset<int> ms1, ms2; // ms1 = max of lower half, ms2 = min of upper half

        auto balance = [&]() {
            while (ms1.size() > p) {
                auto it = prev(ms1.end());
                ms2.insert(*it);
                ms1.erase(it);
            }
            while (ms1.size() < p && !ms2.empty()) {
                auto it = ms2.begin();
                ms1.insert(*it);
                ms2.erase(it);
            }
        };

        for (int i = 0; i < k; ++i) {
            ms1.insert(arr[i]);
        }

        balance();
        sum += (*prev(ms1.end()));

        for (int i = k; i < n; ++i) {
            int out = arr[i - k], in = arr[i];

            // Remove outgoing
            if (ms1.find(out) != ms1.end()) {
                ms1.erase(ms1.find(out));
            } else {
                ms2.erase(ms2.find(out));
            }

            // Add incoming
            if (!ms1.empty() && in <= *prev(ms1.end())) {
                ms1.insert(in);
            } else {
                ms2.insert(in);
            }

            balance();
            sum += (*prev(ms1.end()));
        }
        return sum;
    }

    // Maximize AND of k values from array
  public:
    int maximum_score(int n, vector<int>& arr, int k, int x) {
        vector<int> med_sum(n, 0);
        for (int i = 1; i <= n; i++) {
            med_sum[i - 1] = median_sum(arr, n, i);
        }
        vector<int> candidates = med_sum;
        int X = ~x;
        for (int i = 0; i < candidates.size(); i++) {
            candidates[i] &= X;
        }
        int ans = 0;

        // Try setting bits from high to low
        for (int bit = 60; bit >= 0; --bit) {
            int candidate = ans | (1LL << bit);
            vector<int> filtered;
            for (int b : candidates) {
                if ((b & candidate) == candidate)
                    filtered.push_back(b);
            }
            if ((int)filtered.size() >= k) {
                ans = candidate;
                candidates = filtered;
            }
        }
        ans |= x;
        return ans;
    }
};
