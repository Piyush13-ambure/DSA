/*In a restaurant, two waiters, A and B, receive n orders per day, earning tips as per arrays arr[i] and brr[i] respectively. If A takes the ith order, the tip is arr[i] rupees; if B takes it, the tip is brr[i] rupees.
To maximize total tips, they must distribute the orders such that:
A can handle at most x orders
B can handle at most y orders
Given that x + y ≥ n, all orders can be managed by either A or B. Return the maximum possible total tip after processing all the orders*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int, int>> diff(n);

        // Store the difference and index
        for (int i = 0; i < n; i++) {
            diff[i] = {abs(arr[i] - brr[i]), i};
        }

        // Sort by absolute difference in descending order
        sort(diff.rbegin(), diff.rend());

        long long totalTip = 0;

        for (int i = 0; i < n; i++) {
            int idx = diff[i].second;

            // Assign the order to the waiter who gets more tip
            if ((arr[idx] >= brr[idx] && x > 0) || y == 0) {
                totalTip += arr[idx];
                x--;
            } else {
                totalTip += brr[idx];
                y--;
            }
        }

        return totalTip;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {1, 2, 3, 4, 5}, brr1 = {5, 4, 3, 2, 1};
    cout << sol.maxTip(5, 3, 3, arr1, brr1) << endl; // Output: 21
    
    vector<int> arr2 = {1, 4, 3, 2, 7, 5, 9, 6}, brr2 = {1, 2, 3, 6, 5, 4, 9, 8};
    cout << sol.maxTip(8, 4, 4, arr2, brr2) << endl; // Output: 43
    
    vector<int> arr3 = {8, 7, 15, 19, 16, 16, 18}, brr3 = {1, 7, 15, 11, 12, 31, 9};
    cout << sol.maxTip(7, 3, 4, arr3, brr3) << endl; // Output: 110

    return 0;
}
