/*You are given an array arr[] of integers and two integers a and b, You have to find the maximum possible sum of a contiguous subarray whose length is at least a and at most b.*/
class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();

        // compute prefix sum of the array
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }

        // to store the maximum sum found
        int maxi = arr[a - 1];

        // deque to maintain the minimum prefix in
        // the current window
        deque<int> dq;

        // insert initial prefix 0
        dq.push_back(0);

        // iterate from index 'a' to 'n - 1' (inclusive)
        for (int i = a; i < n; i++) {

            // remove prefix[i - b - 1] from deque if it's
            // outside the valid window
            if (i - b - 1 >= 0) {
                if (dq.front() == arr[i - b - 1]) {
                    dq.pop_front();
                }
            }

            // special case: remove 0 if it falls outside the window
            else if (i - b == 0) {
                if (dq.front() == 0) {
                    dq.pop_front();
                }
            }

            // maintain increasing order in deque (monotonic queue)
            while (!dq.empty() && dq.back() > arr[i - a]) {
                dq.pop_back();
            }

            // insert current prefix sum for future subarray starts
            dq.push_back(arr[i - a]);

            // compute maximum subarray sum ending at index i
            maxi = max(maxi, arr[i] - dq.front());
        }

        return maxi;
    }
};
