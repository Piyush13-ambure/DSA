//Given an array arr[], the task is to find the sum of the maximum elements of every possible non-empty sub-arrays of the given array arr[].

//Note: The answer will always fit into 32 bit interger.


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumOfMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;

        // Finding previous greater element count (distance to the left)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i])
                s.pop();
            left[i] = (s.empty()) ? (i + 1) : (i - s.top());
            s.push(i);
        }

        while (!s.empty()) s.pop(); // Clear stack

        // Finding next greater element count (distance to the right)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] <= arr[i])
                s.pop();
            right[i] = (s.empty()) ? (n - i) : (s.top() - i);
            s.push(i);
        }

        // Calculate the sum of contributions
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i] * left[i] * right[i];
        }

        return sum;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {1, 3, 2};
    cout << "Output: " << sol.sumOfMax(arr1) << endl; // Expected: 15

    vector<int> arr2 = {3, 1};
    cout << "Output: " << sol.sumOfMax(arr2) << endl; // Expected: 7

    vector<int> arr3 = {8, 0, 1};
    cout << "Output: " << sol.sumOfMax(arr3) << endl; // Expected: 26

    return 0;
}
