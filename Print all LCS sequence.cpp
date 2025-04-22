/*You are given two strings s and t. Now your task is to print all longest common sub-sequences in lexicographical order.

Note -  A Sub-sequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101];
    unordered_map<string, set<string>> memo;

    // Function to build LCS length table
    void buildDP(string &s, string &t) {
        int m = s.size();
        int n = t.size();
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtracking to collect all LCS strings
    set<string> backtrack(string &s, string &t, int i, int j) {
        if (i == 0 || j == 0) return {""};

        string key = to_string(i) + "#" + to_string(j);
        if (memo.find(key) != memo.end()) return memo[key];

        set<string> result;

        if (s[i - 1] == t[j - 1]) {
            set<string> temp = backtrack(s, t, i - 1, j - 1);
            for (const string &str : temp) {
                result.insert(str + s[i - 1]);
            }
        } else {
            if (dp[i - 1][j] >= dp[i][j - 1]) {
                set<string> temp = backtrack(s, t, i - 1, j);
                result.insert(temp.begin(), temp.end());
            }
            if (dp[i][j - 1] >= dp[i - 1][j]) {
                set<string> temp = backtrack(s, t, i, j - 1);
                result.insert(temp.begin(), temp.end());
            }
        }

        return memo[key] = result;
    }

    vector<string> all_longest_common_subsequences(string s, string t) {
        memset(dp, 0, sizeof(dp));
        memo.clear();

        buildDP(s, t);
        set<string> lcsSet = backtrack(s, t, s.length(), t.length());

        vector<string> lcsList(lcsSet.begin(), lcsSet.end());
        sort(lcsList.begin(), lcsList.end());

        return lcsList;
    }
};

// Driver code
int main() {
    Solution sol;
    string s1, s2;

    // Example 1
    s1 = "abaaa";
    s2 = "baabaca";
    vector<string> res = sol.all_longest_common_subsequences(s1, s2);
    for (const string &str : res) {
        cout << str << " ";
    }
    cout << endl;

    // Example 2
    s1 = "aaa";
    s2 = "a";
    res = sol.all_longest_common_subsequences(s1, s2);
    for (const string &str : res) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
