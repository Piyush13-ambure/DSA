/*Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.

Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most underrated team - Punjab Kings. Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab. He has stats of runs scored by all N players in the previous season and he wants to find the maximum score for each and every contiguous sub-list of size K to strategize for the game*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int> dq; // Stores indices of array elements
        vector<int> result;

        for (int i = 0; i < n; i++) {
            // Remove elements that are out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements from the back that are smaller than current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add current element index to the deque
            dq.push_back(i);

            // Store the maximum element for the window
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans = obj.max_of_subarrays(arr, n, k);

        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
