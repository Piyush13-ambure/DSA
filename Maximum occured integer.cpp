/*Given n integer ranges, the task is to return the maximum occurring integer in the given ranges. If more than one such integer exists, return the smallest one.
The ranges are in two arrays l[] and r[].  l[i] consists of the starting point of the range and r[i] consists of the corresponding endpoint of the range & a maxx which is the maximum value of r[].

For example, consider the following ranges.
l[] = {2, 1, 3}, r[] = {5, 3, 9}
Ranges represented by the above arrays are.
[2, 5] = {2, 3, 4, 5}
[1, 3] = {1, 2, 3}
[3, 9] = {3, 4, 5, 6, 7, 8, 9}
The maximum occurred integer in these ranges is 3.*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        vector<int> arr(maxx + 2, 0);  // Difference array of size maxx + 2

        // Step 1: Mark ranges in difference array
        for (int i = 0; i < n; i++) {
            arr[l[i]]++;      // Mark start of range
            arr[r[i] + 1]--;  // Mark end of range
        }

        // Step 2: Compute prefix sum to get actual occurrences
        int maxCount = arr[0], maxIndex = 0;
        for (int i = 1; i <= maxx; i++) {
            arr[i] += arr[i - 1];  // Compute prefix sum

            // Step 3: Track max occurrence and smallest index
            if (arr[i] > maxCount) {
                maxCount = arr[i];
                maxIndex = i;
            }
        }

        return maxIndex;  // Smallest integer with max occurrences
    }
};

// Driver code for testing
int main() {
    Solution sol;
    int n1 = 4, l1[] = {1, 4, 3, 1}, r1[] = {15, 8, 5, 4}, maxx1 = 15;
    cout << "Output: " << sol.maxOccured(n1, l1, r1, maxx1) << endl; // Expected: 4

    int n2 = 5, l2[] = {1, 5, 9, 13, 21}, r2[] = {15, 8, 12, 20, 30}, maxx2 = 30;
    cout << "Output: " << sol.maxOccured(n2, l2, r2, maxx2) << endl; // Expected: 5

    return 0;
}
