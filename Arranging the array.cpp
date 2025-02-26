/*You are given an array of size N. Rearrange the given array in-place such that all the negative numbers occur before all non-negative numbers.
(Maintain the order of all -ve and non-negative numbers as given in the original array).*/



#include <iostream>
using namespace std;

class Solution {
public:
    // Merge function to merge two sorted halves while keeping negatives before non-negatives
    void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2];

        // Copying elements into temp arrays
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

        // Merging the arrays while keeping order
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] < 0) arr[k++] = L[i++];
            else if (R[j] < 0) arr[k++] = R[j++];
            else break; // Stop merging as all negatives are placed first
        }

        // Copy remaining elements from L[] (if any)
        while (i < n1) arr[k++] = L[i++];

        // Copy remaining elements from R[] (if any)
        while (j < n2) arr[k++] = R[j++];
    }

    // Merge Sort function
    void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    // Function to rearrange array
    void Rearrange(int arr[], int n) {
        mergeSort(arr, 0, n - 1);
    }
};

int main() {
    Solution sol;
    int arr1[] = {-3, 3, -2, 2};
    int n1 = 4;
    sol.Rearrange(arr1, n1);
    for (int i = 0; i < n1; i++) cout << arr1[i] << " ";
    cout << endl; // Output: -3 -2 3 2

    int arr2[] = {-3, 1, 0, -2};
    int n2 = 4;
    sol.Rearrange(arr2, n2);
    for (int i = 0; i < n2; i++) cout << arr2[i] << " ";
    cout << endl; // Output: -3 -2 1 0

    return 0;
}
