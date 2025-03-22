/*Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. */



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        // Function to expand around the center and count palindromes
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) { // Only count substrings of length >= 2
                    count++;
                }
                left--;
                right++;
            }
        };

        // Iterate through each character and expand around centers
        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);     // Odd length palindromes
            expandAroundCenter(i, i + 1); // Even length palindromes
        }

        return count;
    }
};

// Main function for testing
int main() {
    Solution sol;
    
    string s1 = "abaab";
    cout << sol.countPS(s1) << endl; // Expected output: 3

    string s2 = "aaa";
    cout << sol.countPS(s2) << endl; // Expected output: 3

    string s3 = "abbaeae";
    cout << sol.countPS(s3) << endl; // Expected output: 4

    return 0;
}
