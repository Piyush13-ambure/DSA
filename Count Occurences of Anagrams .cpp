//Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(string &pat, string &txt) {
        int patLen = pat.length(), txtLen = txt.length();
        if (patLen > txtLen) return 0;

        vector<int> patFreq(26, 0), windowFreq(26, 0);
        int count = 0;

        // Populate frequency arrays for `pat` and first window of `txt`
        for (int i = 0; i < patLen; i++) {
            patFreq[pat[i] - 'a']++;
            windowFreq[txt[i] - 'a']++;
        }

        // Compare initial window
        if (patFreq == windowFreq) count++;

        // Slide the window across `txt`
        for (int i = patLen; i < txtLen; i++) {
            windowFreq[txt[i] - 'a']++;             // Include new character
            windowFreq[txt[i - patLen] - 'a']--;    // Remove old character

            if (patFreq == windowFreq) count++;    // Check for anagram
        }

        return count;
    }
};

int main() {
    Solution sol;
    
    string txt1 = "forxxorfxdofr", pat1 = "for";
    cout << sol.search(pat1, txt1) << endl; // Output: 3
    
    string txt2 = "aabaabaa", pat2 = "aaba";
    cout << sol.search(pat2, txt2) << endl; // Output: 4

    return 0;
}
