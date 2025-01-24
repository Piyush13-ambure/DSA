//Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

//Note: If a window does not contain a negative integer, then return 0 for that window.


#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq; // Deque to store indices of negative integers
        
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Add the current index if it's a negative number
            if (arr[i] < 0) {
                dq.push_back(i);
            }

            // Start adding results once the first window is formed
            if (i >= k - 1) {
                if (!dq.empty()) {
                    result.push_back(arr[dq.front()]); // First negative integer in the window
                } else {
                    result.push_back(0); // No negative integer in the window
                }
            }
        }

        return result;
    }
};

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the size of the window (k): ";
    cin >> k;

    Solution sol;
    vector<int> result = sol.FirstNegativeInteger(arr, k);

    cout << "First negative integer in each window of size " << k << ":\n";
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
