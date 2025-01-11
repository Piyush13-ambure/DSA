//Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array.
//  kth smallest
//
//  Created by piyush ambure on 11/01/25.
//

#include <iostream>
#include <vector>
#include <cstdlib> // for rand()
using namespace std;

class Solution {
public:
    // Partition function for Quickselect
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Choose the last element as pivot
        int i = low - 1; // Index for smaller elements

        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    // Quickselect function
    int quickselect(vector<int>& arr, int low, int high, int k) {
        if (low <= high) {
            int pivotIndex = partition(arr, low, high);

            // If pivotIndex matches k, we've found the kth smallest element
            if (pivotIndex == k) {
                return arr[pivotIndex];
            }

            // If k is smaller, search the left part
            if (pivotIndex > k) {
                return quickselect(arr, low, pivotIndex - 1, k);
            }

            // Otherwise, search the right part
            return quickselect(arr, pivotIndex + 1, high, k);
        }
        return -1; // Should not reach here
    }

    // Function to find kth smallest element
    int kthSmallest(vector<int>& arr, int k) {
        return quickselect(arr, 0, arr.size() - 1, k - 1); // k-1 because of 0-based indexing
    }
};

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    if (k > 0 && k <= n) {
        // Create a Solution object and call kthSmallest
        Solution sol;
        int result = sol.kthSmallest(arr, k);
        cout << "The " << k << "th smallest element is: " << result << endl;
    } else {
        cout << "Invalid input: k should be between 1 and " << n << endl;
    }

    return 0;
}
