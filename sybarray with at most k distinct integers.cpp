//You are given an array arr[] of positive integers and an integer k, find the number of subarrays in arr[] where the count of distinct integers is at most k.

//Note: A subarray is a contiguous part of an array.


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to count subarrays with at most k distinct integers
    int atMostK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freqMap; // To store the frequency of elements in the window
        int start = 0, count = 0;

        for (int end = 0; end < n; ++end) {
            freqMap[arr[end]]++; // Add the current element to the window
            
            // If the number of distinct integers exceeds k, shrink the window
            while (freqMap.size() > k) {
                freqMap[arr[start]]--;
                if (freqMap[arr[start]] == 0) {
                    freqMap.erase(arr[start]); // Remove element from the map
                }
                start++;
            }
            
            // Add the number of valid subarrays ending at 'end'
            count += (end - start + 1);
        }

        return count;
    }

    // Function to count subarrays with exactly k distinct integers
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return atMostK(arr, k) - atMostK(arr, k - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    cout << "Number of subarrays with at most " << k << " distinct integers: "
         << sol.atMostK(arr, k) << endl;

    cout << "Number of subarrays with exactly " << k << " distinct integers: "
         << sol.subarraysWithKDistinct(arr, k) << endl;

    return 0;
}
