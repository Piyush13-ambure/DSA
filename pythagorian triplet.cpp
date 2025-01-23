//Given an array arr, return true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to check if the Pythagorean triplet exists or not
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();

        // Square all elements
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * arr[i];
        }

        // Sort the array
        sort(arr.begin(), arr.end());

        // Check for triplets
        for (int c = n - 1; c >= 2; c--) {
            int a = 0, b = c - 1;

            while (a < b) {
                if (arr[a] + arr[b] == arr[c]) {
                    return true; // Found a triplet
                } else if (arr[a] + arr[b] < arr[c]) {
                    a++;
                } else {
                    b--;
                }
            }
        }

        return false; // No triplet found
    }
};

int main() {
    Solution solution;

    vector<int> arr1 = {3, 1, 4, 6, 5};
    vector<int> arr2 = {10, 4, 6, 12, 5};

    cout << "Triplet exists in arr1: " << (solution.pythagoreanTriplet(arr1) ? "True" : "False") << endl;
    cout << "Triplet exists in arr2: " << (solution.pythagoreanTriplet(arr2) ? "True" : "False") << endl;

    return 0;
}
