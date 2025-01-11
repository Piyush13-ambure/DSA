//Given an unsorted array arr of positive integers. One number a from the set [1, 2,....,n] is missing and one number b occurs twice in the array. Find numbers a and b
//  main.cpp
//  missing and repeating
//
//  Created by piyush ambure on 11/01/25.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the missing and duplicate numbers
    pair<int, int> findMissingAndDuplicate(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Cyclic Sort
        for (int i = 0; i < n; ) {
            int correctIndex = arr[i] - 1; // Correct position of arr[i]
            if (arr[i] != arr[correctIndex]) {
                swap(arr[i], arr[correctIndex]);
            } else {
                ++i;
            }
        }

        // Step 2: Find the missing and duplicate numbers
        int missing = -1, duplicate = -1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] != i + 1) {
                missing = i + 1;  // The index + 1 is the missing number
                duplicate = arr[i]; // The number at the incorrect index is the duplicate
                break;
            }
        }

        return {missing, duplicate};
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Create a Solution object and call findMissingAndDuplicate
    Solution sol;
    pair<int, int> result = sol.findMissingAndDuplicate(arr);

    // Output the result
    cout << "Missing number: " << result.first << endl;
    cout << "Duplicate number: " << result.second << endl;

    return 0;
}
