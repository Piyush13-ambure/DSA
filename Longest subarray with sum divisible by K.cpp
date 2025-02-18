//Given an array arr[] and a positive integer k, find the length of the longest subarray with the sum of the elements divisible by k.
//Note: If there is no subarray with sum divisible by k, then return 0.



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> remainderIndex; // Stores first occurrence of remainder
        remainderIndex[0] = -1; // Base case: sum from index 0 to i is divisible by k
        int prefixSum = 0, maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];
            int remainder = prefixSum % k;

            // Convert negative remainder to positive
            if (remainder < 0) remainder += k;

            // If remainder has appeared before, compute subarray length
            if (remainderIndex.find(remainder) != remainderIndex.end()) {
                maxLength = max(maxLength, i - remainderIndex[remainder]);
            } else {
                // Store the first occurrence of remainder
                remainderIndex[remainder] = i;
            }
        }

        return maxLength;
    }
};

// **Main function to test the code**
int main() {
    Solution sol;
    
    vector<int> arr1 = {2, 7, 6, 1, 4, 5};
    int k1 = 3;
    cout << "Output: " << sol.longestSubarrayDivK(arr1, k1) << endl; // Expected: 4

    vector<int> arr2 = {-2, 2, -5, 12, -11, -1, 7};
    int k2 = 3;
    cout << "Output: " << sol.longestSubarrayDivK(arr2, k2) << endl; // Expected: 5

    vector<int> arr3 = {1, 2, -2};
    int k3 = 2;
    cout << "Output: " << sol.longestSubarrayDivK(arr3, k3) << endl; // Expected: 2

    return 0;
}
