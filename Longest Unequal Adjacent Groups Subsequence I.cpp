/*You are given a string array words and a binary array groups both of length n, where words[i] is associated with groups[i].

Your task is to select the longest alternating subsequence from words. A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements in the binary array groups differ. Essentially, you are to choose strings such that adjacent elements have non-matching corresponding bits in the groups array.

Formally, you need to find the longest subsequence of an array of indices [0, 1, ..., n - 1] denoted as [i0, i1, ..., ik-1], such that groups[ij] != groups[ij+1] for each 0 <= j < k - 1 and then find the words corresponding to these indices.

Return the selected subsequence. If there are multiple answers, return any of them.

Note: The elements in words are distinct.

 */


#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);           // dp[i] = length of longest alt subseq ending at i
        vector<int> prev(n, -1);        // To reconstruct path

        int max_len = 1;
        int last_index = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                last_index = i;
            }
        }

        // Reconstruct the sequence
        vector<string> result;
        while (last_index != -1) {
            result.push_back(words[last_index]);
            last_index = prev[last_index];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

// Example usage
int main() {
    Solution sol;

    vector<string> words1 = {"e", "a", "b"};
    vector<int> groups1 = {0, 0, 1};
    vector<string> res1 = sol.getLongestSubsequence(words1, groups1);
    for (const string& w : res1) cout << w << " ";
    cout << endl;

    vector<string> words2 = {"a", "b", "c", "d"};
    vector<int> groups2 = {1, 0, 1, 1};
    vector<string> res2 = sol.getLongestSubsequence(words2, groups2);
    for (const string& w : res2) cout << w << " ";
    cout << endl;

    return 0;
}

