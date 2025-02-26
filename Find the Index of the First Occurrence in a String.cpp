//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to compute the LPS (Longest Prefix Suffix) array
    vector<int> computeLPS(string &needle) {
        int m = needle.length();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while (i < m) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];  // Move to previous LPS position
                } else {
                    lps[i++] = 0;
                }
            }
        }
        return lps;
    }

    // KMP Algorithm to find substring
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;

        vector<int> lps = computeLPS(needle);
        int i = 0, j = 0;  // i for haystack, j for needle

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++; j++;
            }
            if (j == m) return i - j;  // Found needle in haystack
            if (i < n && haystack[i] != needle[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return -1;  // Needle not found
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.strStr("sadbutsad", "sad") << endl;  // Output: 0
    cout << sol.strStr("leetcode", "leeto") << endl; // Output: -1
    return 0;
}
