/*Given an array integers arr[], containing n elements, find the sum of bit differences between all pairs of element in the array. Bit difference of a pair (x, y) is the count of different bits at the same positions in binary representations of x and y.
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 respectively and the first and last bits differ between the two numbers.

Note: (x, y) and (y, x) are considered two separate pair*/



#include <iostream>
using namespace std;

class Solution {
public:
    long long sumBitDifferences(int arr[], int n) {
        long long result = 0;

        // Iterate over all 32-bit positions
        for (int bit = 0; bit < 32; bit++) {
            long long countSet = 0;

            // Count numbers with a set bit at 'bit' position
            for (int i = 0; i < n; i++) {
                if (arr[i] & (1 << bit))
                    countSet++;
            }

            long long countUnset = n - countSet;
            result += (countSet * countUnset * 2);
        }

        return result;
    }
};

// Driver code
int main() {
    Solution sol;
    int arr1[] = {1, 2};
    int n1 = 2;
    cout << "Output: " << sol.sumBitDifferences(arr1, n1) << endl;

    int arr2[] = {1, 3, 5};
    int n2 = 3;
    cout << "Output: " << sol.sumBitDifferences(arr2, n2) << endl;

    return 0;
}
