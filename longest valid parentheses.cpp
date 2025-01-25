//Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

//A parenthesis string is valid if:

//For every opening parenthesis, there is a closing parenthesis.
//The closing parenthesis must be after its opening parenthesis.



#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPrefixSuffix(string &s) {
        int n = s.length();
        vector<int> lps(n, 0); // Longest prefix-suffix array
        
        int len = 0; // Length of the previous longest prefix-suffix
        int i = 1;

        // Build the LPS array
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // The value at lps[n-1] gives the length of the longest prefix which is also a suffix
        // Ensure it is not equal to the entire string
        return (lps[n - 1] == n) ? 0 : lps[n - 1];
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
