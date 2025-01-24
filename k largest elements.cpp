//Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : arr) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element if size exceeds k
            }
        }

        // Extract the k largest elements from the min-heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        // Sort in decreasing order
        sort(result.rbegin(), result.rend());
        return result;
    }
};

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    if (k > n) {
        cout << "k cannot be greater than the size of the array.\n";
        return 0;
    }

    Solution sol;
    vector<int> result = sol.kLargest(arr, k);

    cout << "The " << k << " largest elements in decreasing order are:\n";
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
