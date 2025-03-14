//Given an array arr of n elements in the following format {a1, a2, a3, a4, ... , an/2, b1, b2, b3, b4, ... , bn/2}, the task is shuffle the array to {a1, b1, a2, b2, a3, b3, ... , an/2, bn/2} without using extra space.
//Note that n is even.



#include <iostream>
using namespace std;

class Solution {
public:
    void shuffleArray(int arr[], int n) {
        // Step through the second half and move elements to the correct position
        for (int i = 1, j = n / 2; j < n; j++) {
            int temp = arr[j];

            // Shift all elements to the right to make space
            for (int k = j; k > i; k--) {
                arr[k] = arr[k - 1];
            }

            arr[i] = temp;
            i += 2; // Move to the next alternate position
        }
    }
};

// Driver code
int main() {
    Solution sol;
    int arr[] = {1, 2, 9, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    sol.shuffleArray(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
