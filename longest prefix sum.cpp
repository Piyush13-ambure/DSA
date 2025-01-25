//Given a string of characters s, find the length of the longest prefix which is also a suffix.
//Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPrefixSuffix(string &s) {
        int n = s.length();

        // Create a vector to store the length of the longest prefix-suffix for each position
        vector<int> lps(n, 0);

        int length = 0; // Length of the previous longest prefix-suffix
        int i = 1; // Start from the second character

        while (i < n) {
            if (s[i] == s[length]) {
                // Characters match, increment length and store it in lps[i]
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    // Fallback to the previous longest prefix-suffix length
                    length = lps[length - 1];
                } else {
                    // No match and no fallback, so set lps[i] to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // lps[n-1] contains the length of the longest prefix which is also a suffix
        // Ensure it's not the entire string
        return (lps[n - 1] == n) ? lps[n - 1] - 1 : lps[n - 1];
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution solution;
    int result = solution.longestPrefixSuffix(s);

    cout << "The length of the longest prefix which is also a suffix is: " << result << endl;

    return 0;
}
