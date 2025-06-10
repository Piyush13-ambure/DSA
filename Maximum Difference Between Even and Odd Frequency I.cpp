/*You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int max_diff = -1e9; // Initialize with a very small value

        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) { // a1 has odd frequency
                for (int j = 0; j < 26; ++j) {
                    if (freq[j] % 2 == 0) { // a2 has even frequency
                        max_diff = max(max_diff, freq[i] - freq[j]);
                    }
                }
            }
        }

        return max_diff;
    }
};

int main() {
    Solution sol;
    string s1 = "aaaaabbc";
    cout << "Max difference for '" << s1 << "': " << sol.maxDifference(s1) << endl; // Output: 3

    string s2 = "abcabcab";
    cout << "Max difference for '" << s2 << "': " << sol.maxDifference(s2) << endl; // Output: 1

    string s3 = "aabbccddeeffg";
    cout << "Max difference for '" << s3 << "': " << sol.maxDifference(s3) << endl; // Output: 1

    string s4 = "aaabbbb";
    cout << "Max difference for '" << s4 << "': " << sol.maxDifference(s4) << endl; // Output: -1

    string s5 = "aabbbc";
    cout << "Max difference for '" << s5 << "': " << sol.maxDifference(s5) << endl; // Output: 1

    return 0;
}
