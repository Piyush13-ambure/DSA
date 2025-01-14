//Given an array arr[] of distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
//
//  min swap to sort
//
//  Created by piyush ambure on 14/01/25.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> sortedArr(n);

        // Store array elements with their indices
        for (int i = 0; i < n; i++) {
            sortedArr[i] = {arr[i], i};
        }

        // Sort the array based on element values
        sort(sortedArr.begin(), sortedArr.end());

        // To keep track of visited elements
        vector<bool> visited(n, false);

        int swaps = 0;

        // Traverse the sorted array and check for cycles
        for (int i = 0; i < n; i++) {
            // If the element is already visited or in the correct position, skip
            if (visited[i] || sortedArr[i].second == i) {
                continue;
            }

            // Find the size of the cycle
            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = sortedArr[j].second;
                cycleSize++;
            }

            // If a cycle of size `k` is found, it takes `k-1` swaps to sort
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};
