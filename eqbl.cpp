//Given an array of integers arr[], the task is to find the first equilibrium point in the array.

//The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists
//  main.cpp
//  equlibrium point
//
//  Created by piyush ambure on 14/01/25.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find equilibrium point in the array
    int findEquilibrium(vector<int>& arr) {
        int total_sum = 0;
        int left_sum = 0;
        
        // Calculate total sum of the array
        for (int num : arr) {
            total_sum += num;
        }
        
        // Traverse the array and check for equilibrium point
        for (int i = 0; i < arr.size(); i++) {
            // Right sum is total_sum - left_sum - arr[i]
            total_sum -= arr[i];
            
            // If left_sum is equal to right_sum, we have found the equilibrium point
            if (left_sum == total_sum) {
                return i; // Equilibrium point found at index i
            }
            
            // Update left_sum for the next iteration
            left_sum += arr[i];
        }
        
        // No equilibrium point found
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 5, 2, 2};
    
    int result = sol.findEquilibrium(arr);
    cout << "Equilibrium point index: " << result << endl;  // Output: 2
    
    return 0;
}
