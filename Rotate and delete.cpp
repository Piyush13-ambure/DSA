/*Given an array arr integers. Assume sz to be the initial size of the array. Do the following operations exactly sz/2 times. In every kth (1<= k <= sz/2) operation:

Right-rotate the array clockwise by 1.
Delete the (n– k + 1)th element from begin.
Now, Return the first element of the array.
Note: Here n keeps on decreasing with every operation.*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rotateDelete(vector<int> &arr) {
        int n = arr.size();
        for (int k = 1; k <= n / 2; k++) {
            // Step 1: Right Rotate the array by 1
            int lastElement = arr.back();
            arr.pop_back();
            arr.insert(arr.begin(), lastElement);

            // Step 2: Delete the (n - k + 1)th element from start
            int deleteIndex = n - k;
            arr.erase(arr.begin() + deleteIndex);
        }
        return arr[0]; // First element after all operations
    }
};

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    Solution sol;
    cout << "Output: " << sol.rotateDelete(arr1) << endl; // Expected Output: 3

    vector<int> arr2 = {1, 2, 3, 4};
    cout << "Output: " << sol.rotateDelete(arr2) << endl; // Expected Output: 2

    return 0;
}
