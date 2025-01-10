//You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.
//
//  array leader
//
//  Created by piyush ambure on 10/01/25.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find all leaders in the array
    vector<int> findLeaders(const vector<int>& arr) {
        vector<int> leaders;
        int n = arr.size();

        if (n == 0) {
            return leaders; // Return an empty list if the array is empty
        }

        int maxRight = arr[n - 1]; // The rightmost element is always a leader
        leaders.push_back(maxRight);

        // Traverse the array from right to left
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] >= maxRight) {
                maxRight = arr[i];
                leaders.push_back(arr[i]);
            }
        }

        // Reverse the leaders vector to maintain the order
        reverse(leaders.begin(), leaders.end());

        return leaders;
    }
};

int main() {
    // Example input
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    // Create an object of the Solution class
    Solution solution;
    vector<int> leaders = solution.findLeaders(arr);
    
    // Print the leaders
    cout << "Leaders in the array: ";
    for (int leader : leaders) {
        cout << leader << " ";
    }
}
