/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {  // Check if the prefix is at the start
                prefix = prefix.substr(0, prefix.size() - 1); // Reduce prefix
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

// **Driver Code**
int main() {
    Solution sol;
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};

    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs1) << endl;  // Output: "fl"
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs2) << endl;  // Output: ""

    return 0;
}
