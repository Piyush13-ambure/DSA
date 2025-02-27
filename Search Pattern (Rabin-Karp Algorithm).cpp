/*Given two strings, one is a text string and the other is a pattern string. The task is to print the starting indexes of all the occurrences of the pattern string in the text string. For printing, the Starting Index of a string should be taken as 1. The strings will only contain lowercase English alphabets ('a' to 'z').

*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute LPS array for pattern
    vector<int> computeLPS(string pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // backtrack
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Function to find occurrences of pattern in text
    vector<int> search(string pattern, string text) {
        int n = text.length(), m = pattern.length();
        vector<int> lps = computeLPS(pattern);
        vector<int> result;

        int i = 0, j = 0; // i for text, j for pattern
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) {
                result.push_back(i - j + 1); // Store 1-based index
                j = lps[j - 1]; // Continue searching
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1]; // Jump using LPS
                } else {
                    i++;
                }
            }
        }
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    string text = "geeksforgeeks";
    string pattern = "geek";

    vector<int> res = sol.search(pattern, text);
    for (int index : res) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}
