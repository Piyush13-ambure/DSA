//Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
//Note: Return an empty list in case of no occurrences of pattern.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find all occurrences of pat in txt
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int m = pat.size(), n = txt.size();

        // Compute LPS (Longest Prefix Suffix) array
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        
        while (i < m) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }

        // KMP search algorithm
        i = 0; // Index for txt
        int j = 0; // Index for pat
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++, j++;
            }
            if (j == m) { // Found a match
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};

// Main function to test the implementation
int main() {
    string txt, pat;
    cout << "Enter text: ";
    cin >> txt;
    cout << "Enter pattern: ";
    cin >> pat;

    Solution obj;
    vector<int> occurrences = obj.search(pat, txt);

    if (occurrences.empty()) {
        cout << "No occurrences found.\n";
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : occurrences) {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}
