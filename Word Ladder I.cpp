/*Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
The second part of this problem can be found here.

Note: If no possible way to transform sequence from startWord to targetWord return 0

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        // If the targetWord is not in the dictionary, return 0
        if (dict.find(targetWord) == dict.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({startWord, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            // If we've reached the target word
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.find(temp) != dict.end()) {
                        q.push({temp, steps + 1});
                        dict.erase(temp); // Avoid revisiting
                    }
                }
            }
        }

        return 0; // No transformation found
    }
};

// Example main function
int main() {
    Solution sol;

    vector<string> wordList1 = {"des","der","dfr","dgt","dfs"};
    cout << "Example 1 Output: " << sol.wordLadderLength("der", "dfs", wordList1) << endl;

    vector<string> wordList2 = {"geek", "gefk"};
    cout << "Example 2 Output: " << sol.wordLadderLength("gedk", "geek", wordList2) << endl;

    vector<string> wordList3 = {"poon", "plee", "same", "poie","plea","plie","poin"};
    cout << "Example 3 Output: " << sol.wordLadderLength("toon", "plea", wordList3) << endl;

    return 0;
}
