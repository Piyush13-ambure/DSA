//Given an array arr[]. The task is to sort the array elements by Heap Sort.



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to heapify a subtree rooted at index 'i' in an array of size 'n'
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;       // Initialize largest as root
        int left = 2 * i + 1;  // Left child index
        int right = 2 * i + 2; // Right child index

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not root, swap and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Function to perform heap sort
    void heapSort(vector<int>& arr) {
        int n = arr.size();

        // Build max heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Extract elements one by one from heap
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]); // Move current root to end
            heapify(arr, i, 0);   // Heapify reduced heap
        }
    }
};

int main() {
    Solution solution;
    vector<int> arr;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solution.heapSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
