//Given an array arr[] of N positive integers. Find an integer denoting the maximum XOR subset value in the given array arr[]
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubsetXOR(int arr[], int N) {
        int index = 0; // Index to maintain the position of basis elements

        // Traverse over each bit position (from MSB to LSB)
        for (int bit = 31; bit >= 0; bit--) {
            // Find the maximum element with the current bit set
            int maxIndex = index;
            int maxElement = INT_MIN;

            for (int i = index; i < N; i++) {
                if ((arr[i] & (1 << bit)) && arr[i] > maxElement) {
                    maxElement = arr[i];
                    maxIndex = i;
                }
            }

            // If no element has the current bit set, skip this bit
            if (maxElement == INT_MIN) {
                continue;
            }

            // Swap the found element with the current index element
            swap(arr[index], arr[maxIndex]);

            // Use this element to eliminate the current bit from all other elements
            for (int i = 0; i < N; i++) {
                if (i != index && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[index];
                }
            }

            // Move to the next index
            index++;
        }

        // Compute the result by XORing all basis elements
        int result = 0;
        for (int i = 0; i < index; i++) {
            result ^= arr[i];
        }

        return result;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    int arr1[] = {2, 4, 5};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Maximum XOR subset value: " << solution.maxSubsetXOR(arr1, N1) << endl;

    int arr2[] = {9, 8, 5};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Maximum XOR subset value: " << solution.maxSubsetXOR(arr2, N2) << endl;

    return 0;
}
