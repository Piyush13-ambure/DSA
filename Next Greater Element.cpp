//Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
//If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1
//  main.cpp
//  Next Greater Element
//
//  Created by piyush ambure on 12/01/25.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1); // Initialize result array with -1
        stack<int> st; // Stack to store indices of elements

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Pop elements from the stack that are less than or equal to the current element
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack is not empty, the top element is the next greater element
            if (!st.empty()) {
                result[i] = arr[st.top()];
            }

            // Push the current index onto the stack
            st.push(i);
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    vector<int> result = sol.nextLargerElement(arr);

    cout << "Next greater elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
