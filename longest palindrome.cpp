//Given a string s, your task is to find the longest palindromic substring within s.

//A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

//A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.
//Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    // Function to find the longest palindromic substring
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0; // Start index of the longest palindrome
        int maxLength = 1; // Length of the longest palindrome

        // Dynamic Programming table
        bool dp[n][n] = {false};

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for substrings of length greater than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1; // Ending index of the substring

                // Check if the current substring is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, maxLength);
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    string s1 = "babad";
    cout << "Longest Palindromic Substring: " << solution.longestPalindrome(s1) << endl;

    string s2 = "cbbd";
    cout << "Longest Palindromic Substring: " << solution.longestPalindrome(s2) << endl;

    string s3 = "a";
    cout << "Longest Palindromic Substring: " << solution.longestPalindrome(s3) << endl;

    string s4 = "forgeeksskeegfor";
    cout << "Longest Palindromic Substring: " << solution.longestPalindrome(s4) << endl;

    return 0;
}
