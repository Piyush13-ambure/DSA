//Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.
#include <iostream>
#include <vector>
#include <cmath> // For ceil function
using namespace std;

class Solution {
public:
    // Function to merge two sorted arrays without extra space
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int gap = ceil((double)(n + m) / 2);

        while (gap > 0) {
            int i = 0, j = gap;

            // Traverse and compare elements in both arrays
            while (j < (n + m)) {
                if (j < n && a[i] > a[j]) {
                    // Swap in the first array
                    swap(a[i], a[j]);
                } else if (i < n && j >= n && a[i] > b[j - n]) {
                    // Swap between arrays
                    swap(a[i], b[j - n]);
                } else if (i >= n && j >= n && b[i - n] > b[j - n]) {
                    // Swap in the second array
                    swap(b[i - n], b[j - n]);
                }
                i++;
                j++;
            }

            // Update the gap
            if (gap == 1) {
                gap = 0; // End the loop
            } else {
                gap = ceil((double)gap / 2);
            }
        }
    }
};

int main() {
    vector<int> a = {1, 4, 7, 8, 10};
    vector<int> b = {2, 3, 9};

    Solution sol;
    sol.mergeArrays(a, b);

    cout << "Array a: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    cout << "Array b: ";
    for (int x : b) cout << x << " ";
    cout << endl;

    return 0;
}
