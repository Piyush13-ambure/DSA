//You have a garden with n flowers lined up in a row. The height of ith flower is ai units. You will water them for k days. In one day you can water w continuous flowers (you can do this only once in a single day). Whenever you water a flower its height increases by 1 unit. You need to maximize the height of the smallest flower all the time.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& a, int n, int k, int w, int mid) {
        vector<int> water(n, 0); // Difference array for tracking added water
        int totalWater = 0; // Total water used

        for (int i = 0; i < n; i++) {
            if (i >= w) totalWater -= water[i - w]; // Remove water effect beyond range

            if (a[i] + totalWater < mid) { // If current height is less than mid
                int needed = mid - (a[i] + totalWater);
                if (k < needed) return false; // Not enough days left
                k -= needed;
                totalWater += needed;
                water[i] += needed; // Mark this position as water source
            }
        }
        return true;
    }

    long long int maximizeMinHeight(int n, int k, int w, vector<int>& a) {
        int low = *min_element(a.begin(), a.end()); // Minimum flower height
        int high = low + k; // Max height achievable in k days
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(a, n, k, w, mid)) {
                ans = mid; // Store the best minimum height
                low = mid + 1; // Try for a higher minimum height
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

// Driver function
int main() {
    Solution sol;
    vector<int> a1 = {2, 2, 2, 2, 1, 1};
    cout << sol.maximizeMinHeight(6, 2, 3, a1) << endl; // Output: 2

    vector<int> a2 = {5, 8};
    cout << sol.maximizeMinHeight(2, 5, 1, a2) << endl; // Output: 9

    return 0;
}
