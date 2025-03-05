/*Given an integer array arr[ ], your task is to find the minimum number of increment operations required to make all the array elements unique. i.e. no value in the array should occur more than once. In one operation, a value can be incremented by 1 only.

Note: The answer will always fit into a 32-bit integer.*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // Step 1: Sort the array
        int moves = 0;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] <= arr[i - 1]) {
                int increment = arr[i - 1] - arr[i] + 1;
                arr[i] += increment;  // Step 2: Make it unique
                moves += increment;   // Step 3: Count the increments
            }
        }
        return moves;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
