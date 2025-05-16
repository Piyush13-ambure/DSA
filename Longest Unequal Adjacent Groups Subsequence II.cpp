/*You are given a string array words, and an array groups, both arrays having length n.

The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.

You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:

For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.
Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.

Note: strings in words may be unequal in length.

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int hammingDistance(const string& a, const string& b) {
        if (a.size() != b.size()) return -1;
        int dist = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++dist;
            if (dist > 1) return -1;
        }
        return dist;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);        // dp[i] = length of longest sequence ending at i
        vector<int> prev(n, -1);     // prev[i] = previous index in the path
        int max_len = 1, end_idx = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].size() == words[j].size() &&
                    hammingDistance(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                end_idx = i;
            }
        }

        // Reconstruct path
        vector<string> result;
        int curr = end_idx;
        while (curr != -1) {
            result.push_back(words[curr]);
            curr = prev[curr];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

// Main function to test
int main() {
    Solution sol;

    vector<string> words1 = {"abcd", "abed", "aecd", "aebd", "afbd"};
    vector<int> groups1 = {1, 2, 1, 2, 3};

    vector<string> result = sol.getWordsInLongestSubsequence(words1, groups1);

    cout << "Longest valid subsequence:\n";
    for (const string& word : result) {
        cout << word << endl;
    }

    return 0;
}
