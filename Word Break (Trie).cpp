/*Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 
Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.


*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to check if A can be segmented into words in B
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> dict(B.begin(), B.end());
        int n = A.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty string can be segmented

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(A.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n] ? 1 : 0;
    }
};

// ---------- Main Function to Test ----------
int main() {
    string A1 = "ilike";
    vector<string> B = { "i", "like", "sam", "sung", "samsung",
                         "mobile", "ice", "cream", "icecream",
                         "man", "go", "mango" };

    Solution sol;
    cout << "Output for 'ilike': " << sol.wordBreak(A1, B) << endl;

    string A2 = "ilikesamsung";
    cout << "Output for 'ilikesamsung': " << sol.wordBreak(A2, B) << endl;

    string A3 = "ilikemobileman";
    cout << "Output for 'ilikemobileman': " << sol.wordBreak(A3, B) << endl;

    string A4 = "ilikepizza";
    cout << "Output for 'ilikepizza' (not in dict): " << sol.wordBreak(A4, B) << endl;

    return 0;
}
