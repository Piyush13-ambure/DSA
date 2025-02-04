//Given a string s, return the longest palindromic substring in s.


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to expand around center and return longest palindrome length
    pair<int, int> expandFromCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1}; // Return valid palindrome boundaries
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindrome
            auto [l1, r1] = expandFromCenter(s, i, i);
            // Even-length palindrome
            auto [l2, r2] = expandFromCenter(s, i, i + 1);

            if (r1 - l1 + 1 > maxLength) {
                start = l1;
                maxLength = r1 - l1 + 1;
            }
            if (r2 - l2 + 1 > maxLength) {
                start = l2;
                maxLength = r2 - l2 + 1;
            }
        }
        return s.substr(start, maxLength);
    }
};

int main() {
    string s;
    cin >> s;
    
    Solution obj;
    cout << obj.longestPalindrome(s) << endl;

    return 0;
}
