//
// Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
//  sort 0s and 1s and 2s
//
//  Created by piyush ambure on 10/01/25.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to sort the array containing only 0s, 1s, and 2s
    void sortArray(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;
        
        // Traverse the array with three pointers (low, mid, high)
        while (mid <= high) {
            if (arr[mid] == 0) {
                // Swap arr[low] and arr[mid], move both pointers
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                // Move mid pointer if the element is 1
                mid++;
            } else {
                // Swap arr[mid] and arr[high], move high pointer
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array (only 0s, 1s, and 2s): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Create a Solution object and call sortArray
    Solution sol;
    sol.sortArray(arr);
    
    // Output the sorted array
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
