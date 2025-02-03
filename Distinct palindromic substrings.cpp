//Given a string str of lowercase ASCII characters, Count the number of distinct continuous palindromic sub-strings which are present in the string str.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int palindromeSubStrs(string s) {
        int n = s.length();
        unordered_set<string> palindromes;

        // Expand Around Centers
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                palindromes.insert(s.substr(left, right - left + 1));
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);   // Odd-length palindromes
            expand(i, i+1); // Even-length palindromes
        }

        return palindromes.size();
    }
};

// Driver code
int main() {
    Solution sol;
    cout << sol.palindromeSubStrs("abaaa") << endl; // Output: 5
    cout << sol.palindromeSubStrs("geek") << endl;  // Output: 4
    return 0;
}

