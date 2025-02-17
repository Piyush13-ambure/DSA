//Given a string s, your task is to find the smallest window length that contains all the characters of the given string at least one time.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubString(string &s) {
        unordered_set<char> uniqueChars(s.begin(), s.end()); // Unique characters in s
        int numUnique = uniqueChars.size(); // Total unique characters

        unordered_map<char, int> freq;
        int left = 0, minLen = INT_MAX, count = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            if (freq[s[right]] == 1) count++; // A new unique character is added
            
            while (count == numUnique) { // Found a valid window
                minLen = min(minLen, right - left + 1);
                freq[s[left]]--;
                if (freq[s[left]] == 0) count--; // A unique character is removed
                left++; // Shrink the window
            }
        }
        return minLen;
    }
};

// Main function for testing
int main() {
    Solution obj;

    string s1 = "AABBBCBBAC";
    cout << obj.findSubString(s1) << endl; // Output: 3

    string s2 = "aaab";
    cout << obj.findSubString(s2) << endl; // Output: 2

    string s3 = "GEEKSGEEKSFOR";
    cout << obj.findSubString(s3) << endl; // Output: 8

    return 0;
}
