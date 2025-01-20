//Given an array arr of n integers, count all pairs (arr[i], arr[j]) in it such that i*arr[i] > j*arr[j] and 0 ≤ i < j < n.

//Note: 0-based Indexing is followed.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(int arr[], int n) {
        int count = 0;

        // Iterate through all pairs (i, j)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i * arr[i] > j * arr[j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = solution.countPairs(arr, n);

    cout << "The number of pairs is: " << result << endl;

    return 0;
}
