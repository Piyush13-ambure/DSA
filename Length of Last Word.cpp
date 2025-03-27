/*Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Step 1: Ignore trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<string> testCases = {
        "Hello World",
        "   fly me   to   the moon  ",
        "luffy is still joyboy"
    };

    for (const string &s : testCases) {
        cout << "Length of last word in \"" << s << "\": " << solution.lengthOfLastWord(s) << endl;
    }

    return 0;
}
