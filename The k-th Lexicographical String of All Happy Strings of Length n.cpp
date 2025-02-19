/*A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateHappyStrings(int n, string curr, vector<string>& happyStrings) {
        if (curr.length() == n) {
            happyStrings.push_back(curr);
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) {  // Ensure no adjacent duplicates
                generateHappyStrings(n, curr + ch, happyStrings);
            }
        }
    }
    
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        generateHappyStrings(n, "", happyStrings);
        
        return (k <= happyStrings.size()) ? happyStrings[k - 1] : "";
    }
};

// **Main function to test the solution**
int main() {
    Solution sol;
    
    cout << sol.getHappyString(1, 3) << endl; // Output: "c"
    cout << sol.getHappyString(1, 4) << endl; // Output: ""
    cout << sol.getHappyString(3, 9) << endl; // Output: "cab"

    return 0;
}
