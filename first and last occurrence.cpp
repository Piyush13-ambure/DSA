//Given a sorted array arr with possibly some duplicates, the task is to find the first and last occurrences of an element x in the given array.
//Note: If the number x is not found in the array then return both the indices as -1.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> find(vector<int>& arr, int x) {
        int first = -1, last = -1;
        int low = 0, high = arr.size() - 1;
        
        // Find the first occurrence of x
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                first = mid;
                high = mid - 1; // Search the left half
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low = 0, high = arr.size() - 1;

        // Find the last occurrence of x
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                last = mid;
                low = mid + 1; // Search the right half
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {first, last};
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;

    vector<int> result = solution.find(arr, x);
    cout << "First occurrence: " << result[0] << "\n";
    cout << "Last occurrence: " << result[1] << "\n";

    return 0;
}
