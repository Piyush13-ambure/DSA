//Given an array a of integers of length n, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftSmaller(int n, int a[]) {
        vector<int> result;
        stack<int> s; // Stack to maintain smaller elements
        
        for (int i = 0; i < n; i++) {
            // Pop elements from stack while they are >= current element
            while (!s.empty() && s.top() >= a[i]) {
                s.pop();
            }
            
            // If stack is empty, no smaller element exists
            if (s.empty()) {
                result.push_back(-1);
            } else {
                result.push_back(s.top()); // Top of stack is the nearest smaller element
            }
            
            // Push the current element onto the stack
            s.push(a[i]);
        }
        
        return result;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
