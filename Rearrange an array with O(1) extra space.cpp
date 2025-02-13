/*Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].

NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.*/



#include <iostream>
using namespace std;

class Solution {
public:
    // Function to rearrange the array in O(1) space complexity.
    void arrange(long long arr[], int n) {
        // Step 1: Encode the new value at each index
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] + (arr[arr[i]] % n) * n;
        }

        // Step 2: Decode the values to get the final transformation
        for (int i = 0; i < n; i++) {
            arr[i] /= n;
        }
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    long long arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solution.arrange(arr, n);

    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
