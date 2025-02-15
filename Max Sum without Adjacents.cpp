//Given an array arr containing positive integers. Find the maximum sum of any possible subsequence such that no two numbers in the subsequence should be adjacent in array arr.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the maximum sum without adjacent elements
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev1 = 0; // Previous sum including the current element
        int prev2 = 0; // Previous sum excluding the current element

        for (int num : arr) {
            int newInclude = prev2 + num;  // Include current element
            int newExclude = max(prev1, prev2); // Exclude current element
            prev2 = prev1;
            prev1 = max(newInclude, newExclude);
        }

        return prev1;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout << "Maximum sum without adjacent elements: " << obj.findMaxSum(arr) << endl;

    return 0;
}
