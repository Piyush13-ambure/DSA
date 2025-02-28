//Given a binary string s. Perform r iterations on string s, where in each iteration 0 becomes 01 and 1 becomes 10. Find the nth character (considering 0 based indexing) of the string after performing these r iterations (see examples for better understanding).


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nthCharacter(string s, int r, int n) {
        while (r > 0) {
            // Find parent index in the previous iteration
            int parent_index = n / 2;
            
            // Determine the character transformation
            if (s[parent_index] == '0') {
                if (n % 2 == 0) s[n] = '0'; // Left half of "01"
                else s[n] = '1';            // Right half of "01"
            } else {
                if (n % 2 == 0) s[n] = '1'; // Left half of "10"
                else s[n] = '0';            // Right half of "10"
            }
            
            // Move to the parent character for the next iteration
            n = parent_index;
            r--;
        }
        return s[n];
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, n;
        string s;
        cin >> s >> r >> n;
        Solution ob;
        cout << ob.nthCharacter(s, r, n) << endl;
    }
    return 0;
}
