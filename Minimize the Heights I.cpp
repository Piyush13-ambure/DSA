/*Given a array arr[] and positive integer k denoting heights of towers, you have to modify the height of each tower either by increasing or decreasing them by k only once.

Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

Note: A slight modification of the problem can be found here. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;  // Only one tower, no difference

        sort(arr.begin(), arr.end());  // Step 1: Sort the array

        int minDiff = arr[n - 1] - arr[0];  // Initial difference (without modification)
        
        for (int i = 1; i < n; i++) {
            int minHeight = min(arr[0] + k, arr[i] - k);   // New minimum height
            int maxHeight = max(arr[i - 1] + k, arr[n - 1] - k); // New maximum height
            
            if (minHeight < 0) continue;  // Heights cannot be negative
            
            minDiff = min(minDiff, maxHeight - minHeight); // Update min difference
        }

        return minDiff;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 5, 8, 10};
    int k = 2;
    cout << "Minimum difference: " << obj.getMinDiff(arr, k) << endl;

    return 0;
}
