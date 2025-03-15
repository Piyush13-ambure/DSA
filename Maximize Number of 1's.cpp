//Given a binary array arr[] (containing only 0s and 1s) and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, right = 0, max_len = 0, zero_count = 0;
        
        while (right < arr.size()) {
            if (arr[right] == 0) zero_count++;

            // If zero count exceeds k, shrink window from the left
            while (zero_count > k) {
                if (arr[left] == 0) zero_count--;
                left++;
            }

            // Update max length of window with at most k flips
            max_len = max(max_len, right - left + 1);
            right++;
        }
        
        return max_len;
    }
};

// Main function to test the implementation
int main() {
    Solution solution;

    vector<int> arr1 = {1, 0, 1};
    int k1 = 1;
    cout << "Output: " << solution.maxOnes(arr1, k1) << endl; // Expected: 3

    vector<int> arr2 = {1, 0, 0, 1, 0, 1, 0, 1};
    int k2 = 2;
    cout << "Output: " << solution.maxOnes(arr2, k2) << endl; // Expected: 5

    vector<int> arr3 = {1, 1};
    int k3 = 2;
    cout << "Output: " << solution.maxOnes(arr3, k3) << endl; // Expected: 2

    return 0;
}
