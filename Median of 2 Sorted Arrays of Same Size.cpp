//Given two sorted arrays a[] and b[] of equal size, find and return the median of the combined array after merging them into a single sorted array.



#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int n = a.size();
        if (n == 1) {
            return (a[0] + b[0]) / 2.0;
        }

        if (a[0] > b[0]) swap(a, b); // Ensure 'a' is the smaller array

        int low = 0, high = n;
        while (low <= high) {
            int partitionA = (low + high) / 2;
            int partitionB = n - partitionA;

            int leftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
            int rightA = (partitionA == n) ? INT_MAX : a[partitionA];

            int leftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
            int rightB = (partitionB == n) ? INT_MAX : b[partitionB];

            if (leftA <= rightB && leftB <= rightA) {
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            } else if (leftA > rightB) {
                high = partitionA - 1;
            } else {
                low = partitionA + 1;
            }
        }
        return -1; // This should never be reached
    }
};

int main() {
    Solution sol;
    
    vector<int> a1 = {-5, 3, 6, 12, 15};
    vector<int> b1 = {-12, -10, -6, -3, 4};
    cout << "Median: " << sol.medianOf2(a1, b1) << endl; // Expected output: 0

    vector<int> a2 = {2, 3, 5, 7};
    vector<int> b2 = {10, 12, 14, 16};
    cout << "Median: " << sol.medianOf2(a2, b2) << endl; // Expected output: 8.5

    vector<int> a3 = {-5};
    vector<int> b3 = {-6};
    cout << "Median: " << sol.medianOf2(a3, b3) << endl; // Expected output: -5.5

    return 0;
}
