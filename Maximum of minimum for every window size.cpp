//Given an array of integers arr[] of size N, the task is to find the maximum of the minimum values for every possible window size in the array, where the window size ranges from 1 to N.

//More formally, for each window size k, determine the smallest element in all windows of size k, and then find the largest value among these minimums where 1<=k<=N.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxOfMin(vector<int>& arr) {
        int N = arr.size();
        vector<int> prev(N, -1), next(N, N);
        stack<int> s;

        // Compute Previous Smaller Element
        for (int i = 0; i < N; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) prev[i] = s.top();
            s.push(i);
        }

        // Clear stack for Next Smaller Element computation
        while (!s.empty()) s.pop();

        // Compute Next Smaller Element
        for (int i = N - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) next[i] = s.top();
            s.push(i);
        }

        // Array to store maximum of minimum for every window size
        vector<int> result(N + 1, 0);

        // Compute the answer for each window size
        for (int i = 0; i < N; i++) {
            int windowSize = next[i] - prev[i] - 1;
            result[windowSize] = max(result[windowSize], arr[i]);
        }

        // Fill remaining values (Right to Left pass)
        for (int i = N - 1; i >= 1; i--) {
            result[i] = max(result[i], result[i + 1]);
        }

        // Remove the extra index 0
        result.erase(result.begin());

        return result;
    }
};

// Main function to test the implementation
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    vector<int> res = obj.maxOfMin(arr);

    cout << "Maximum of minimums for every window size: ";
    for (int num : res) cout << num << " ";
    cout << endl;

    return 0;
}
