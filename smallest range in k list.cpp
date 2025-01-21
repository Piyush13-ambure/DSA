//Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    pair<int, int> findSmallestRange(int KSortedArray[][100], int n, int k) {
        // Min-heap to store elements as {value, list_index, element_index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        int minRange = INT_MAX;  // Store the smallest range found
        int rangeStart = 0, rangeEnd = 0;
        int currentMax = INT_MIN;  // Track the current maximum in the heap

        // Step 1: Initialize the heap with the first element of each list
        for (int i = 0; i < k; i++) {
            minHeap.push({KSortedArray[i][0], i, 0});
            currentMax = max(currentMax, KSortedArray[i][0]);
        }

        // Step 2: Process the heap until we exhaust any list
        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();

            int currentMin = top[0];
            int listIndex = top[1];
            int elementIndex = top[2];

            // Update the smallest range if a better one is found
            if (currentMax - currentMin < minRange) {
                minRange = currentMax - currentMin;
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }

            // Move to the next element in the same list
            if (elementIndex + 1 < n) {
                int nextValue = KSortedArray[listIndex][elementIndex + 1];
                minHeap.push({nextValue, listIndex, elementIndex + 1});
                currentMax = max(currentMax, nextValue);
            } else {
                // If we reach the end of any list, stop
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    int KSortedArray[3][100] = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}
    };

    pair<int, int> result = solution.findSmallestRange(KSortedArray, 5, 3);

    cout << "Smallest range is: [" << result.first << ", " << result.second << "]" << endl;

    return 0;
}
