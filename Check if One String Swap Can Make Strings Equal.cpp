//You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

//Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;  // Already equal, no swap needed

        vector<int> diff;  // Store indices where s1[i] != s2[i]

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) diff.push_back(i);
            if (diff.size() > 2) return false; // More than 2 mismatches
        }

        return (diff.size() == 2 && 
                s1[diff[0]] == s2[diff[1]] && 
                s1[diff[1]] == s2[diff[0]]);
    }
};

int main() {
    Solution obj;
    cout << obj.areAlmostEqual("bank", "kanb") << endl;  // Output: true
    cout << obj.areAlmostEqual("attack", "defend") << endl;  // Output: false
    cout << obj.areAlmostEqual("kelb", "kelb") << endl;  // Output: true
    return 0;
}
