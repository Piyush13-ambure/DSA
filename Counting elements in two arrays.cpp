//You are given two unsorted arrays a[] and b[]. Both arrays may contain duplicate elements. For each element in a[], your task is to count how many elements in b[] are less than or equal to that element.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countEleLessThanOrEqual(vector<int>& a, vector<int>& b) {
        vector<int> result;
        
        // Sort array b[] for efficient searching
        sort(b.begin(), b.end());

        // Process each element in a[]
        for (int x : a) {
            // Find how many elements in b[] are ≤ x
            int count = upper_bound(b.begin(), b.end(), x) - b.begin();
            result.push_back(count);
        }
        
        return result;
    }
};

// Main function to test the program
int main() {
    vector<int> a = {4, 8, 7, 5, 1};
    vector<int> b = {4, 48, 3, 0, 1, 1, 5};
    
    Solution obj;
    vector<int> res = obj.countEleLessThanOrEqual(a, b);
    
    cout << "Output: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
