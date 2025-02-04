//Given an array arr[] and two integers say, x and y, find the number of sub-arrays in which the number of occurrences of x is equal to the number of occurrences of y.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> freq;
        int prefix_sum = 0, count = 0;
        
        freq[0] = 1;  // Initial condition (to count subarrays starting from index 0)

        for (int num : arr) {
            if (num == x) prefix_sum += 1;
            else if (num == y) prefix_sum -= 1;
            
            // If prefix_sum has been seen before, it means there are valid subarrays
            if (freq.find(prefix_sum) != freq.end()) {
                count += freq[prefix_sum];
            }
            
            // Store/update frequency of the prefix sum
            freq[prefix_sum]++;
        }

        return count;
    }
};

int main() {
    vector<int> arr = {1, 2, 1, 2, 1, 2, 1, 3, 4};
    int x = 1, y = 2;
    
    Solution obj;
    cout << "Number of valid subarrays: " << obj.sameOccurrence(arr, x, y) << endl;
    
    return 0;
}

