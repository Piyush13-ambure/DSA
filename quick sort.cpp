//Implement Quick Sort, a Divide and Conquer algorithm, to sort an array, arr[] in ascending order. Given an array, arr[], with starting index low and ending index high, complete the functions partition() and quickSort(). Use the last element as the pivot so that all elements less than or equal to the pivot come before it, and elements greater than the pivot follow it.


#include <vector>
using namespace std;

class Solution {
  public:
    // Function to sort an array using the quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            // Partition the array around the pivot and get its position
            int pivotIndex = partition(arr, low, high);
            
            // Recursively sort elements before and after the partition
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    // Function that takes the last element as pivot, places the pivot element
    // at its correct position in sorted array, and places all smaller elements
    // to the left of the pivot and all greater elements to the right.
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Choose the last element as pivot
        int i = low - 1;       // Index for elements smaller than the pivot
        
        for (int j = low; j < high; j++) {
            // If the current element is smaller than or equal to the pivot
            if (arr[j] <= pivot) {
                i++; // Move the smaller element index forward
                swap(arr[i], arr[j]); // Swap the elements
            }
        }
        // Place the pivot at its correct position
        swap(arr[i + 1], arr[high]);
        return i + 1; // Return the index of the pivot
    }
};
