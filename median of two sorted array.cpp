//Given two sorted arrays a[] and b[], find and return the median of the combined array after merging them into a single sorted array.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) return medianOf2(b, a); // Ensure a is the smaller array

        int n1 = a.size(), n2 = b.size();
        int low = 0, high = n1;

        while (low <= high) {
            int partitionA = (low + high) / 2;
            int partitionB = (n1 + n2 + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
            int minRightA = (partitionA == n1) ? INT_MAX : a[partitionA];

            int maxLeftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
            int minRightB = (partitionB == n2) ? INT_MAX : b[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((n1 + n2) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                high = partitionA - 1;
            } else {
                low = partitionA + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted or invalid.");
    }
};

int main() {
    vector<int> a = {1, 3, 8};
    vector<int> b = {7, 9, 10, 11};

    Solution solution;
    try {
        double result = solution.medianOf2(a, b);
        cout << "Median of the two sorted arrays is: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
