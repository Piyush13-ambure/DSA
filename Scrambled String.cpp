//Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.

//Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
//Below is one possible representation of str = coder:
 
//To scramble the string, we may choose any non-leaf node and swap its two children.  Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder. Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.
//Note: Scrambled string is not the same as an Anagram.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> dp;
    
    bool isScramble(string S1, string S2) {
        if (S1 == S2) return true;
        if (S1.length() != S2.length()) return false;

        string key = S1 + " " + S2;
        if (dp.find(key) != dp.end()) return dp[key];

        int n = S1.length();
        string sortedS1 = S1, sortedS2 = S2;
        sort(sortedS1.begin(), sortedS1.end());
        sort(sortedS2.begin(), sortedS2.end());
        if (sortedS1 != sortedS2) return dp[key] = false;

        for (int i = 1; i < n; i++) {
            // Case 1: No swapping
            if (isScramble(S1.substr(0, i), S2.substr(0, i)) &&
                isScramble(S1.substr(i), S2.substr(i))) 
                return dp[key] = true;

            // Case 2: Swapping
            if (isScramble(S1.substr(0, i), S2.substr(n - i)) &&
                isScramble(S1.substr(i), S2.substr(0, n - i))) 
                return dp[key] = true;
        }

        return dp[key] = false;
    }
};

int main() {
    Solution obj;
    string S1 = "coder", S2 = "ocder";
    cout << (obj.isScramble(S1, S2) ? "Yes" : "No") << endl;

    S1 = "abcde", S2 = "caebd";
    cout << (obj.isScramble(S1, S2) ? "Yes" : "No") << endl;
    
    return 0;
}
