/*Given a string, find the longest substring which is palindrome in Linear time O(N).

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The only line of each test case contains a string.

Output:
For each test case print the Longest Palindromic Substring. If there are multiple such substrings of same length, print the one which appears first in the input string.*/


#include <iostream>
#include <vector>

using namespace std;

string LongestPalindromeSubString(string text) {
    int n = text.size();
    if (n == 0) return "";

    // Transform string: insert '#' between characters and around
    string s = "@#";
    for (char c : text) {
        s += c;
        s += "#";
    }
    s += "$"; // Add a sentinel character at the end

    int len = s.size();
    vector<int> P(len, 0);
    int C = 0, R = 0, maxLen = 0, centerIndex = 0;

    // Manacher's Algorithm
    for (int i = 1; i < len - 1; i++) {
        int mirror = 2 * C - i; // Mirror of 'i' around center 'C'

        if (i < R)
            P[i] = min(R - i, P[mirror]);

        // Expand around center
        while (s[i + 1 + P[i]] == s[i - 1 - P[i]])
            P[i]++;

        // Update center and right boundary
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        // Track max palindrome length
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Extract longest palindrome
    int start = (centerIndex - maxLen) / 2; // Convert back to original index
    return text.substr(start, maxLen);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string text;
        cin >> text;
        cout << LongestPalindromeSubString(text) << endl;
    }
    return 0;
}
