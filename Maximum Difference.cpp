//Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.


#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

class Solution {
public:
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        vector<int> leftSmaller(n, 0);
        vector<int> rightSmaller(n, 0);
        stack<int> s;

        // Finding the nearest smaller element to the left
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                leftSmaller[i] = s.top();
            }
            s.push(arr[i]);
        }

        // Clear the stack for the next operation
        while (!s.empty()) {
            s.pop();
        }

        // Finding the nearest smaller element to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                rightSmaller[i] = s.top();
            }
            s.push(arr[i]);
        }

        // Calculate the maximum absolute difference
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(leftSmaller[i] - rightSmaller[i]));
        }

        return maxDiff;
    }
};

// Main function to test the solution
int main() {
    vector<int> arr = {2, 4, 8, 7, 7, 9, 3};
    Solution sol;
    cout << "Maximum Absolute Difference: " << sol.findMaxDiff(arr) << endl;
    return 0;
}
