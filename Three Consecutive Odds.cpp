/*
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int num : arr) {
            if (num % 2 == 1) {
                count++;
                if (count == 3) return true;
            } else {
                count = 0;  // reset count if not odd
            }
        }
        return false;
    }
};

// Main function to test the above logic
int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {2, 6, 4, 1};
    cout << "Test Case 1 Output: " << (sol.threeConsecutiveOdds(arr1) ? "true" : "false") << endl;

    // Test Case 2
    vector<int> arr2 = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << "Test Case 2 Output: " << (sol.threeConsecutiveOdds(arr2) ? "true" : "false") << endl;

    return 0;
}
