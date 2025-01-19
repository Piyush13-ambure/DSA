//Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

//Return the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered [2,3,4] or only board [1] or nothing but not boards [2,4,5].
#include <iostream>
#include <vector>
#include <numeric> // For accumulate
#include <algorithm> // For max
using namespace std;

class Solution {
public:
    // Function to check if it's possible to allocate books such that
    // no student gets more than 'maxPages'.
    bool isPossible(vector<int>& arr, int n, int k, int maxPages) {
        int students = 1; // Start with the first student
        int pagesAllocated = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > maxPages) {
                return false; // A single book exceeds the limit
            }

            if (pagesAllocated + arr[i] > maxPages) {
                // Allocate to the next student
                students++;
                pagesAllocated = arr[i];

                if (students > k) {
                    return false; // More students required than available
                }
            } else {
                pagesAllocated += arr[i];
            }
        }
        return true;
    }

    // Function to find the minimum of the maximum pages
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();

        if (n < k) {
            return -1; // Not enough books for each student to get at least one
        }

        int low = *max_element(arr.begin(), arr.end()); // Minimum possible value
        int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible value
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, n, k, mid)) {
                result = mid; // Try for a better (lower) answer
                high = mid - 1;
            } else {
                low = mid + 1; // Increase the range
            }
        }
        return result;
    }
};

int main() {
    vector<int> arr = {12, 34, 67, 90}; // Example input
    int k;

    cout << "Enter the number of students: ";
    cin >> k;

    Solution sol;
    int result = sol.findPages(arr, k);

    if (result != -1) {
        cout << "The minimum of the maximum pages is: " << result << endl;
    } else {
        cout << "Allocation is not possible." << endl;
    }

    return 0;
}
