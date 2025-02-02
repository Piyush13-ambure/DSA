//Given a string s, find the length of the longest substringwithout repeating characters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLen = 0, left = 0;

        for (int right = 0; right < s.length(); right++) {
            if (charIndex.find(s[right]) != charIndex.end() && charIndex[s[right]] >= left) {
                // Move left pointer to remove duplicate
                left = charIndex[s[right]] + 1;
            }

            // Store the last occurrence of the character
            charIndex[s[right]] = right;

            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;  // Output: 3 ("abc")
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;    // Output: 1 ("b")
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;   // Output: 3 ("wke")
    cout << sol.lengthOfLongestSubstring("") << endl;        // Output: 0 (empty string)
    cout << sol.lengthOfLongestSubstring("dvdf") << endl;    // Output: 3 ("vdf")
    return 0;
}
