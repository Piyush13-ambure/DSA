//Given a string S and a pattern P consisting of lowercase characters. The task is to check if pattern P exists in the given string S or not.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) {
        int M = pat.length();
        int N = txt.length();

        // Step 1: Build LPS array
        vector<int> lps(M, 0);
        int len = 0, i = 1;

        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];  // Reduce the length
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Search using LPS array
        i = 0; // Index for txt[]
        int j = 0; // Index for pat[]
        
        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == M) {
                return true; // Pattern found
            }
            else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false; // Pattern not found
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.search("abc", "xabcx") << endl;  // Output: 1 (true)
    cout << sol.search("xyz", "abcdef") << endl; // Output: 0 (false)
    return 0;
}
