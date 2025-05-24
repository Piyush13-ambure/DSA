/*You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(x) != string::npos) {
                result.push_back(i);
            }
        }
        return result;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    vector<string> words1 = {"leet", "code"};
    char x1 = 'e';
    vector<int> res1 = sol.findWordsContaining(words1, x1);
    cout << "Output: ";
    for (int i : res1) cout << i << " ";
    cout << endl;

    vector<string> words2 = {"abc", "bcd", "aaaa", "cbc"};
    char x2 = 'a';
    vector<int> res2 = sol.findWordsContaining(words2, x2);
    cout << "Output: ";
    for (int i : res2) cout << i << " ";
    cout << endl;

    vector<string> words3 = {"abc", "bcd", "aaaa", "cbc"};
    char x3 = 'z';
    vector<int> res3 = sol.findWordsContaining(words3, x3);
    cout << "Output: ";
    for (int i : res3) cout << i << " ";
    cout << endl;

    return 0;
}
