//Given an array arr and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Step 1: Count elements ≤ k
        int count_k = 0;
        for (int num : arr) {
            if (num <= k) count_k++;
        }
        
        if (count_k == 0 || count_k == n) return 0; // Already grouped together
        
        // Step 2: Find the number of unfavorable elements in the first window
        int bad = 0;
        for (int i = 0; i < count_k; i++) {
            if (arr[i] > k) bad++;
        }

        // Step 3: Sliding Window
        int min_swaps = bad;
        for (int i = count_k; i < n; i++) {
            // Remove the first element of the window
            if (arr[i - count_k] > k) bad--;
            
            // Add the new element to the window
            if (arr[i] > k) bad++;

            // Update min_swaps
            min_swaps = min(min_swaps, bad);
        }

        return min_swaps;
    }
};

// Main function to test
int main() {
    Solution sol;
    vector<int> arr = {2, 1, 5, 6, 3};
    int k = 3;

    int result = sol.minSwap(arr, k);
    cout << "Minimum swaps required: " << result << endl;
    
    return 0;
}
