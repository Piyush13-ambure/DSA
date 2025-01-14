//Given an array of integers arr[]. Find the Inversion Count in the array.
//Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.
//  main.cpp
//  count inversion
//
//  Created by piyush ambure on 14/01/25.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Merge function to count inversions and sort the array
    int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left;    // Starting index for left subarray
        int j = mid + 1; // Starting index for right subarray
        int k = left;    // Starting index to be merged in temp
        int invCount = 0;

        // Traverse both subarrays and merge
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                invCount += (mid - i + 1); // Count inversions
            }
        }

        // Copy the remaining elements of left subarray, if any
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy the remaining elements of right subarray, if any
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy the sorted subarray into the original array
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return invCount;
    }

    // Function to use merge sort and count inversions
    int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
        int invCount = 0;
        if (left < right) {
            int mid = (left + right) / 2;

            // Count inversions in left subarray
            invCount += mergeSortAndCount(arr, temp, left, mid);

            // Count inversions in right subarray
            invCount += mergeSortAndCount(arr, temp, mid + 1, right);

            // Count split inversions
            invCount += mergeAndCount(arr, temp, left, mid, right);
        }
        return invCount;
    }

    // Function to count inversions in the array
    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);
        return mergeSortAndCount(arr, temp, 0, n - 1);
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int invCount = solution.inversionCount(arr);
    cout << "The inversion count is: " << invCount << endl;

    return 0;
}
