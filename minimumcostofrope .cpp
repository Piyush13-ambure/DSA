//Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths.
//  main.cpp
//  minimum cost of rope
//
//  Created by piyush ambure on 11/01/25.
//
#include <iostream>
#include <vector>
#include <queue> // For priority_queue
using namespace std;

class Solution {
public:
    // Function to calculate the minimum cost to connect all ropes
    int minCostToConnectRopes(vector<int>& arr) {
        // Min-heap to store rope lengths
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Insert all rope lengths into the min-heap
        for (int length : arr) {
            minHeap.push(length);
        }

        int totalCost = 0;

        // While there is more than one rope in the heap
        while (minHeap.size() > 1) {
            // Extract the two smallest ropes
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();

            // Calculate the cost to connect these two ropes
            int cost = first + second;

            // Add the cost to the total
            totalCost += cost;

            // Push the combined rope back into the heap
            minHeap.push(cost);
        }

        return totalCost;
    }
};

int main() {
    int n;
    cout << "Enter the number of ropes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the lengths of the ropes: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Create a Solution object and call minCostToConnectRopes
    Solution sol;
    int result = sol.minCostToConnectRopes(arr);

    // Output the result
    cout << "Minimum cost to connect all ropes: " << result << endl;

    return 0;
}
