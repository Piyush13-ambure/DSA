/*
Topics
Companies
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int word_len = words[0].size();
        int total_words = words.size();
        int total_len = word_len * total_words;
        int n = s.size();

        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }

        // Try different offsets to cover all cases
        for (int i = 0; i < word_len; i++) {
            unordered_map<string, int> window_count;
            int left = i, count = 0;

            for (int right = i; right + word_len <= n; right += word_len) {
                string word = s.substr(right, word_len);

                if (word_count.find(word) != word_count.end()) {
                    window_count[word]++;
                    count++;

                    // If a word is over-counted, shift left until valid
                    while (window_count[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        window_count[left_word]--;
                        count--;
                        left += word_len;
                    }

                    // If window matches `total_len`, store the start index
                    if (count == total_words) {
                        result.push_back(left);
                    }
                } 
                else {  // Reset window if an invalid word is found
                    window_count.clear();
                    count = 0;
                    left = right + word_len;
                }
            }
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    string s;
    int n;
    vector<string> words;

    // Test input
    cin >> s >> n;
    words.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    vector<int> result = sol.findSubstring(s, words);
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
