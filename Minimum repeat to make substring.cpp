/*Given two strings s1 and s2. Return a minimum number of times s1 has to be repeated such that s2 is a substring of it. If s2 can never be a substring then return -1.

Note: Both the strings contain only lowercase letters.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRepeats(string &s1, string &s2) {
        int count = 1;  
        string repeated_s1 = s1;

        // Repeat s1 until its length is at least as long as s2
        while (repeated_s1.length() < s2.length()) {
            repeated_s1 += s1;
            count++;
        }

        // Check if s2 is a substring of the repeated s1
        if (repeated_s1.find(s2) != string::npos) {
            return count;
        }

        // Add one more repetition to check boundary spanning cases
        repeated_s1 += s1;
        count++;

        if (repeated_s1.find(s2) != string::npos) {
            return count;
        }

        // If s2 is still not found, return -1
        return -1;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution obj;
        cout << obj.minRepeats(s1, s2) << endl;
    }
    return 0;
}
