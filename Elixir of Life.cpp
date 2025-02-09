/*Flamel is making the Elixir of Life but he is missing a secret ingredient, a set of contiguous plants (substring) from the Garden of Eden.
The garden consists of various plants represented by string S, where each letter represents a different plant.  But the prophecy has predicted that the correct set of plants required to make the potion will appear in the same contiguous pattern (substring) at the beginning of the forest (prefix), the end of the forest (suffix), and will also be the most frequent sequence present in the entire forest.

Identify the substring of plants required to make the elixir and find out the number of times it appears in the forest. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(string S) {
        int n = S.length();
        
        // Compute the prefix function (LPS array from KMP)
        vector<int> lps(n, 0);
        int j = 0;
        for (int i = 1; i < n; i++) {
            while (j > 0 && S[i] != S[j]) {
                j = lps[j - 1];
            }
            if (S[i] == S[j]) {
                j++;
            }
            lps[i] = j;
        }

        // Get all prefix-suffix candidates
        unordered_set<string> candidates;
        int len = lps[n - 1];
        while (len > 0) {
            candidates.insert(S.substr(0, len));
            len = lps[len - 1];
        }

        // Count occurrences of all substrings
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                freq[S.substr(i, j - i + 1)]++;
            }
        }

        // Find max frequency among prefix-suffix substrings
        int maxFreq = 1;
        for (const string& sub : candidates) {
            maxFreq = max(maxFreq, freq[sub]);
        }

        return maxFreq;
    }
};
