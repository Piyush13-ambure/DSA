/*Given an array of integers arr[] of length N, every element appears thrice except for one which occurs once.
Find that element which occurs once.*/


#include <iostream>
using namespace std;

class Solution {
public:
    int singleElement(int arr[], int N) {
        int result = 0;

        // Iterate over all 32 bits (assuming integer size is 32 bits)
        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            // Count occurrences of the current bit across all numbers
            for (int i = 0; i < N; i++) {
                if (arr[i] & (1 << bit)) {
                    count++;
                }
            }

            // If count is not a multiple of 3, this bit belongs to the unique element
            if (count % 3 != 0) {
                result |= (1 << bit);
            }
        }

        return result;
    }
};

// Driver code
int main() {
    Solution sol;
    int arr1[] = {1, 10, 1, 1};
    int n1 = 4;
    cout << "Output: " << sol.singleElement(arr1, n1) << endl;  // Expected Output: 10

    int arr2[] = {3, 2, 1, 34, 34, 1, 2, 34, 2, 1};
    int n2 = 10;
    cout << "Output: " << sol.singleElement(arr2, n2) << endl;  // Expected Output: 3

    return 0;
}
