/*Given a string s and a dictionary dict[] of valid words, you need to return all possible ways to break the string s into sentence such that each word in the sentence is a valid dictionary word.
You are allowed to use a valid word multiple times in the sentence.*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> wordBreak(vector<string>& dict, string& s) {
        unordered_set<string> dictSet(dict.begin(), dict.end());
        return dfs(s, dictSet);
    }

private:
    vector<string> dfs(string s, unordered_set<string>& dict) {
        if (memo.count(s)) return memo[s];
        if (s.empty()) return {""};

        vector<string> result;

        for (int i = 1; i <= s.size(); ++i) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                vector<string> suffixWays = dfs(s.substr(i), dict);
                for (const string& suffix : suffixWays) {
                    result.push_back(word + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};

// Main function to test the above solution
int main() {
    Solution sol;

    // Test Case 1
    vector<string> dict1 = {"lik", "like", "egfg", "gfg"};
    string s1 = "likegfg";
    vector<string> result1 = sol.wordBreak(dict1, s1);

    cout << "Output for \"likegfg\":\n";
    for (const string& sentence : result1) {
        cout << sentence << endl;
    }

    cout << "\n";

    // Test Case 2
    vector<string> dict2 = {"for", "geeks"};
    string s2 = "geeksforgeeks";
    Solution sol2;  // fresh memoization
    vector<string> result2 = sol2.wordBreak(dict2, s2);

    cout << "Output for \"geeksforgeeks\":\n";
    for (const string& sentence : result2) {
        cout << sentence << endl;
    }

    return 0;
}
