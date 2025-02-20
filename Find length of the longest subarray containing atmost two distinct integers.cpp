//Given an array arr[] containing positive elements, the task is to find the length of the longest subarray of an input array containing at most two distinct integers.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> freq_map;
        int left = 0, max_length = 0;

        for (int right = 0; right < arr.size(); right++) {
            freq_map[arr[right]]++;  // Include new element in the window

            while (freq_map.size() > 2) {  // More than 2 distinct numbers?
                freq_map[arr[left]]--;
                if (freq_map[arr[left]] == 0)
                    freq_map.erase(arr[left]); // Remove if frequency becomes 0
                left++;  // Shrink window
            }

            max_length = max(max_length, right - left + 1);  // Update max length
        }

        return max_length;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr1 = {2, 1, 2};
    cout << sol.totalElements(arr1) << endl; // Output: 3

    vector<int> arr2 = {3, 1, 2, 2, 2, 2};
    cout << sol.totalElements(arr2) << endl; // Output: 5

    return 0;
}
