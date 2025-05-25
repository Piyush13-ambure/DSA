/*You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int res = 0;
        bool central = false;

        for (const string& word : words) {
            string rev = string(word.rbegin(), word.rend());
            if (count[rev] > 0) {
                res += 4;
                count[rev]--;
            } else {
                count[word]++;
            }
        }

        for (auto& [word, freq] : count) {
            if (word[0] == word[1] && freq > 0) {
                res += 2;
                break; // only one such central word is allowed
            }
        }

        return res;
    }
};

// Driver code
int main() {
    Solution sol;
    
    vector<string> words1 = {"lc","cl","gg"};
    vector<string> words2 = {"ab","ty","yt","lc","cl","ab"};
    vector<string> words3 = {"cc","ll","xx"};

    cout << "Example 1 Output: " << sol.longestPalindrome(words1) << endl; // 6
    cout << "Example 2 Output: " << sol.longestPalindrome(words2) << endl; // 8
    cout << "Example 3 Output: " << sol.longestPalindrome(words3) << endl; // 2

    return 0;
}
