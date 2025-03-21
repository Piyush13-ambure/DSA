/*Given N numbers in an array, your task is to keep at most the top K numbers with respect to their frequency.

In other words, you have to iterate over the array, and after each index, determine the top K most frequent numbers until that iteration and store them in an array in decreasing order of frequency. An array will be formed for each iteration and stored in an array of arrays. If the total number of distinct elements is less than K, then keep all the distinct numbers in the array. If two numbers have equal frequency, place the smaller number first in the array.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<vector<int>> result;
        unordered_map<int, int> freq;
        set<pair<int, int>> sorted_set; // (frequency, number) sorted in decreasing order

        for (int i = 0; i < N; i++) {
            int num = arr[i];
            
            // Remove old frequency record from the set
            if (freq[num] > 0) {
                sorted_set.erase({-freq[num], num});
            }
            
            // Increase frequency
            freq[num]++;
            
            // Insert new frequency record into the set
            sorted_set.insert({-freq[num], num});
            
            // Collect top K elements
            vector<int> topK;
            int count = 0;
            for (auto it = sorted_set.begin(); it != sorted_set.end() && count < K; ++it, ++count) {
                topK.push_back(it->second);
            }
            
            result.push_back(topK);
        }
        
        return result;
    }
};

// Driver Code
int main() {
    int N = 5, K = 4;
    vector<int> arr = {5, 2, 1, 3, 2};

    Solution obj;
    vector<vector<int>> res = obj.kTop(arr, N, K);

    for (auto& row : res) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
