//Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

//Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> unionResult;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            // Avoid duplicates in the first array
            if (i > 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            }
            // Avoid duplicates in the second array
            if (j > 0 && b[j] == b[j - 1]) {
                j++;
                continue;
            }
            if (a[i] < b[j]) {
                unionResult.push_back(a[i]);
                i++;
            } else if (a[i] > b[j]) {
                unionResult.push_back(b[j]);
                j++;
            } else {
                // When both elements are equal
                unionResult.push_back(a[i]);
                i++;
                j++;
            }
        }

        // Process remaining elements of array a
        while (i < a.size()) {
            if (i == 0 || a[i] != a[i - 1]) {
                unionResult.push_back(a[i]);
            }
            i++;
        }

        // Process remaining elements of array b
        while (j < b.size()) {
            if (j == 0 || b[j] != b[j - 1]) {
                unionResult.push_back(b[j]);
            }
            j++;
        }

        return unionResult;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 5, 5, 6};

    vector<int> result = solution.findUnion(a, b);

    cout << "Union of the arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
