/*Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
The first part of this problem can be found here.


Your Task:
You don't need to read or print anything, Your task is to complete the function findSequences() which takes startWord, targetWord and wordList as input parameter and returns a list of list of strings of the shortest transformation sequence from startWord to targetWord.
Note: You don't have to return -1 in case of no possible sequence. Just return the Empty List.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> results;
        if (dict.find(endWord) == dict.end()) return results;

        unordered_map<string, vector<string>> adjList;
        unordered_map<string, int> visitedLevel;

        queue<vector<string>> q;
        q.push({beginWord});
        visitedLevel[beginWord] = 1;

        int level = 1;
        bool foundEnd = false;

        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> thisLevelVisited;

            for (int i = 0; i < size; i++) {
                vector<string> path = q.front(); q.pop();
                string word = path.back();

                for (int j = 0; j < word.length(); ++j) {
                    string temp = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[j] = c;
                        if (dict.find(temp) != dict.end()) {
                            if (visitedLevel.find(temp) == visitedLevel.end() || visitedLevel[temp] == level + 1) {
                                vector<string> newPath = path;
                                newPath.push_back(temp);
                                q.push(newPath);
                                thisLevelVisited.insert(temp);

                                if (temp == endWord) {
                                    foundEnd = true;
                                    results.push_back(newPath);
                                }
                            }
                        }
                    }
                }
            }

            for (const string& w : thisLevelVisited) {
                visitedLevel[w] = level + 1;
            }

            if (foundEnd) break;
            ++level;
        }

        return results;
    }
};

int main() {
    Solution sol;

    // Example 1
    string startWord1 = "der";
    string targetWord1 = "dfs";
    vector<string> wordList1 = {"des", "der", "dfr", "dgt", "dfs"};
    auto result1 = sol.findSequences(startWord1, targetWord1, wordList1);

    cout << "Example 1 Output:\n";
    for (auto& seq : result1) {
        for (auto& word : seq) cout << word << " ";
        cout << endl;
    }

    // Example 2
    string startWord2 = "gedk";
    string targetWord2 = "geek";
    vector<string> wordList2 = {"geek", "gefk"};
    auto result2 = sol.findSequences(startWord2, targetWord2, wordList2);

    cout << "\nExample 2 Output:\n";
    for (auto& seq : result2) {
        for (auto& word : seq) cout << word << " ";
        cout << endl;
    }

    return 0;
}
