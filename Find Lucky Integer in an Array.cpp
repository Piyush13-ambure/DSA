/*Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Count the frequency of each element
        for (int num : arr) {
            freq[num]++;
        }

        int result = -1;

        // Find the largest lucky integer
        for (auto& pair : freq) {
            if (pair.first == pair.second) {
                result = max(result, pair.first);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {2, 2, 3, 4};
    cout << "Output: " << sol.findLucky(arr1) << endl;  // Expected: 2

    vector<int> arr2 = {1, 2, 2, 3, 3, 3};
    cout << "Output: " << sol.findLucky(arr2) << endl;  // Expected: 3

    vector<int> arr3 = {2, 2, 2, 3, 3};
    cout << "Output: " << sol.findLucky(arr3) << endl;  // Expected: -1

    return 0;
}
