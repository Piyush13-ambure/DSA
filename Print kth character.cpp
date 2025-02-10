//Given a string S consisting of lower alphabetic characters. Find K-th character in the string formed by concatenating all the unique substring of the given string in a sorted form.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char PrintKthCharacter(string S, int K) {
        int n = S.length();
        set<string> substrings;

        // Step 1: Generate all unique substrings
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = i; j < n; j++) {
                temp += S[j];
                substrings.insert(temp);
            }
        }

        // Step 2: Sort substrings lexicographically
        vector<string> sortedSubstrings(substrings.begin(), substrings.end());

        // Step 3: Concatenate sorted substrings
        string concatenated;
        for (const string &sub : sortedSubstrings) {
            concatenated += sub;
            if (concatenated.length() >= K) { // Stop early if possible
                return concatenated[K - 1];
            }
        }

        return '?'; // Edge case (should not happen given constraints)
    }
};

// Driver code
int main() {
    Solution sol;
    cout << sol.PrintKthCharacter("banana", 10) << endl;  // Output: 'n'
    cout << sol.PrintKthCharacter("abcdefg", 10) << endl; // Output: 'd'
    return 0;
}
