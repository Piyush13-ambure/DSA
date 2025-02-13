//Given a string s, find the length of the longest substring without repeating characters

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestUniqueSubstring(string &s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0, left = 0;

        for (int right = 0; right < s.length(); right++) {
            if (charIndex.find(s[right]) != charIndex.end()) {
                left = max(left, charIndex[s[right]] + 1);
            }
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Length of the longest substring without repeating characters: " 
         << solution.longestUniqueSubstring(s) << endl;

    return 0;
}
