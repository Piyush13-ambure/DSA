//Given an array arr[] of integers, determine whether it contains a triplet whose sum equals zero. Return true if such a triplet exists, otherwise, return false#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find triplets with zero sum.
    bool findTriplets(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Sort the array

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            // Two-pointer approach to find pairs with sum = -arr[i]
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == 0) {
                    return true; // Triplet found
                } else if (sum < 0) {
                    left++; // Increase the sum
                } else {
                    right--; // Decrease the sum
                }
            }
        }
        return false; // No triplet found
    }
};

int main() {
    vector<int> arr;
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    Solution sol;
    if (sol.findTriplets(arr)) {
        cout << "Triplet with zero sum exists." << endl;
    } else {
        cout << "No triplet with zero sum exists." << endl;
    }

    return 0;
}
