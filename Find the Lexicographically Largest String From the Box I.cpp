/*Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
All the split words are put into a box.
Find the lexicographically largest string from the box after all the rounds are finished.

 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string maxStr = "";

    // Helper function to perform DFS to generate all unique splits
    void dfs(const string &word, int start, int friendsLeft, vector<string> &currentSplit) {
        int n = word.size();
        
        // Base case: only one friend left, give them the rest of the word
        if (friendsLeft == 1) {
            string lastPart = word.substr(start);
            currentSplit.push_back(lastPart);
            // Check all parts and update maxStr
            for (const string &s : currentSplit) {
                if (s > maxStr) maxStr = s;
            }
            currentSplit.pop_back();
            return;
        }

        // Try placing a split at all valid positions
        for (int i = start + 1; i <= n - friendsLeft + 1; ++i) {
            string part = word.substr(start, i - start);
            currentSplit.push_back(part);
            dfs(word, i, friendsLeft - 1, currentSplit);
            currentSplit.pop_back();
        }
    }

    string answerString(string word, int numFriends) {
        vector<string> currentSplit;
        maxStr = "";
        dfs(word, 0, numFriends, currentSplit);
        return maxStr;
    }
};

// Main function for testing
int main() {
    Solution sol;

    string word1 = "dbca";
    int friends1 = 2;
    cout << sol.answerString(word1, friends1) << endl; // Output: "dbc"

    string word2 = "gggg";
    int friends2 = 4;
    cout << sol.answerString(word2, friends2) << endl; // Output: "g"

    string word3 = "zabc";
    int friends3 = 2;
    cout << sol.answerString(word3, friends3) << endl; // Output: "z"

    return 0;
}
