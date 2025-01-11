//Given an array arr[] of integers and an integer k, your task is to find the maximum value for each contiguous subarray of size k. The output should be an array of maximum values corresponding to each contiguous subarray
//  main.cpp
//  Queue
//
//  Created by piyush ambure on 11/01/25.
//
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    // Function to find the maximum of each subarray of size k
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result; // To store the maximum of each subarray
        deque<int> dq; // Deque to store indices of useful elements

        for (int i = 0; i < arr.size(); ++i) {
            // Remove elements from the front of deque that are out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove elements from the back of deque that are smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // Once we have processed the first k elements, add the maximum of the current window
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    // Create a Solution object and call maxOfSubarrays
    Solution sol;
    vector<int> result = sol.maxOfSubarrays(arr, k);

    // Output the result
    cout << "Maximum of each subarray of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
