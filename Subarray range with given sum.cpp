//Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to count the number of subarrays which add up to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int, int> prefix_count; // Stores frequency of prefix sums
        int curr_sum = 0; // Stores prefix sum
        int count = 0; // Stores result

        prefix_count[0] = 1; // To handle cases where prefix sum itself equals tar

        for (int num : arr) {
            curr_sum += num; // Update prefix sum

            // Check if there exists a prefix sum that allows a valid subarray
            if (prefix_count.find(curr_sum - tar) != prefix_count.end()) {
                count += prefix_count[curr_sum - tar]; // Add occurrences
            }

            // Store/update the prefix sum count
            prefix_count[curr_sum]++;
        }
        
        return count;
    }
};

// Main function to test the implementation
int main() {
    Solution solution;

    vector<int> arr1 = {10, 2, -2, -20, 10};
    int tar1 = -10;
    cout << "Output: " << solution.subArraySum(arr1, tar1) << endl; // Expected: 3

    vector<int> arr2 = {1, 4, 20, 3, 10, 5};
    int tar2 = 33;
    cout << "Output: " << solution.subArraySum(arr2, tar2) << endl; // Expected: 1

    return 0;
}
