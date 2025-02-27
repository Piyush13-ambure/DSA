//Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
//Note: You need to change the given array arr[] in place.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = arr.size();
        int index = 0;

        // Push first k+1 elements into the minHeap
        for (int i = 0; i <= k && i < n; i++)
            minHeap.push(arr[i]);

        // Process the remaining elements
        for (int i = k + 1; i < n; i++) {
            arr[index++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        // Extract remaining elements from the heap
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    
    sol.nearlySorted(arr, k);
    
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    
    return 0;
}
