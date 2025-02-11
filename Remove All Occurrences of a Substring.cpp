/*Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Continue removing the part from the string until no occurrences are found
        size_t pos;
        while ((pos = s.find(part)) != string::npos) {
            s.erase(pos, part.length()); // Remove the part from string
        }
        return s;
    }
};

int main() {
    Solution sol;

    cout << "Output: " << sol.removeOccurrences("daabcbaabcbc", "abc") << endl; // Expected: "dab"
    cout << "Output: " << sol.removeOccurrences("axxxxyyyyb", "xy") << endl;     // Expected: "ab"

    return 0;
}
