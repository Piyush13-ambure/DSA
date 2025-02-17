//Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> prev(3);

        // Base case: First day values
        prev[0] = arr[0][0]; 
        prev[1] = arr[0][1]; 
        prev[2] = arr[0][2];

        for (int i = 1; i < n; i++) {
            vector<int> curr(3);
            curr[0] = arr[i][0] + max(prev[1], prev[2]); // If Running today, pick best from Fighting/Learning
            curr[1] = arr[i][1] + max(prev[0], prev[2]); // If Fighting today, pick best from Running/Learning
            curr[2] = arr[i][2] + max(prev[0], prev[1]); // If Learning today, pick best from Running/Fighting
            prev = curr; // Update for next iteration
        }
        
        // Maximum points from the last day
        return max({prev[0], prev[1], prev[2]});
    }
};

// Main function for testing
int main() {
    Solution obj;

    vector<vector<int>> arr1 = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    cout << obj.maximumPoints(arr1) << endl; // Output: 11

    vector<vector<int>> arr2 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    cout << obj.maximumPoints(arr2) << endl; // Output: 6

    vector<vector<int>> arr3 = {{4, 2, 6}};
    cout << obj.maximumPoints(arr3) << endl; // Output: 6

    return 0;
}
