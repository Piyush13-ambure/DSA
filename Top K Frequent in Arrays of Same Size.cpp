//Given a non-empty integer array arr[] of size n, find the top k elements which have the highest frequency in the array.

//Note: If two numbers have the same frequencies, then the larger number should be given more preference.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
        unordered_map<int, int> freqMap;
        
        // Step 1: Count frequencies of elements
        for (int num : arr) {
            freqMap[num]++;
        }

        // Step 2: Use a max heap (priority queue) with custom sorting
        priority_queue<pair<int, int>> maxHeap;
        
        for (auto &entry : freqMap) {
            maxHeap.push({entry.second, entry.first}); // (frequency, number)
        }

        // Step 3: Extract top k elements
        vector<int> result;
        while (k-- && !maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr1 = {3, 1, 4, 4, 5, 2, 6, 1};
    int k1 = 2;
    vector<int> result1 = sol.topKFrequent(arr1, k1);
    
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    int k2 = 4;
    vector<int> result2 = sol.topKFrequent(arr2, k2);
    
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
