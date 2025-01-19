//Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key. Return -1 if the key is not found.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to search for a key in a sorted and rotated array
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                return mid; // Key found
            }

            // Check if the left half is sorted
            if (arr[low] <= arr[mid]) {
                // If key lies in the left half
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Otherwise, the right half must be sorted
            else {
                // If key lies in the right half
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1; // Key not found
    }
};

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int key;

    cout << "Enter the key to search: ";
    cin >> key;

    Solution sol;
    int result = sol.search(arr, key);

    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found." << endl;
    }

    return 0;
}
