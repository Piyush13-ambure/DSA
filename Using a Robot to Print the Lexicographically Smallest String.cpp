/*You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.

 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        string result;
        stack<char> t;

        // minChar[i] stores the smallest character from s[i] to s[n-1]
        vector<char> minChar(n);
        minChar[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minChar[i] = min(s[i], minChar[i + 1]);
        }

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);
            // Keep popping from stack if the top is <= the smallest remaining char
            while (!t.empty() && (i == n - 1 || t.top() <= minChar[i + 1])) {
                result += t.top();
                t.pop();
            }
        }

        return result;
    }
};

// Main function to test the code
int main() {
    Solution sol;

    vector<string> testCases = {
        "zza",     // Expected: "azz"
        "bac",     // Expected: "abc"
        "bdda"     // Expected: "addb"
    };

    for (const auto& test : testCases) {
        cout << "Input: " << test << endl;
        cout << "Output: " << sol.robotWithString(test) << endl << endl;
    }

    return 0;
}
