/*Given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist). If there are multiple peak elements, return index of any one of them. The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".

Note: Consider the element before the first element and the element after the last element to be negative infinity.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakElement(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            bool leftOK = (mid == 0) || (arr[mid] > arr[mid - 1]);
            bool rightOK = (mid == n - 1) || (arr[mid] > arr[mid + 1]);

            if (leftOK && rightOK) {
                return mid;
            } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
                high = mid - 1; // peak is on the left side
            } else {
                low = mid + 1;  // peak is on the right side
            }
        }
        return -1; // Should never reach here as per the problem constraints
    }
};

// Function to verify the correctness of the peak index
bool isPeak(vector<int>& arr, int idx) {
    int n = arr.size();
    if (idx < 0 || idx >= n) return false;

    int left = (idx == 0) ? INT_MIN : arr[idx - 1];
    int right = (idx == n - 1) ? INT_MIN : arr[idx + 1];

    return arr[idx] > left && arr[idx] > right;
}

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 4, 5, 7, 8, 3},
        {10, 20, 15, 2, 23, 90, 80},
        {1, 2, 3}
    };

    Solution sol;

    for (auto& arr : testCases) {
        int peakIdx = sol.peakElement(arr);
        cout << (isPeak(arr, peakIdx) ? "true" : "false") << endl;
    }

    return 0;
}
