/*You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.


  */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> buckets(26);  // To store indexes of each character
        string result;

        for (char c : s) {
            if (c == '*') {
                // Find smallest char in result and remove it
                for (int i = 0; i < 26; ++i) {
                    if (!buckets[i].empty()) {
                        int lastPos = buckets[i].back();
                        buckets[i].pop_back();
                        result.erase(lastPos, 1);
                        // After erasing, need to update indices in buckets
                        for (int j = 0; j < 26; ++j) {
                            for (int& pos : buckets[j]) {
                                if (pos > lastPos) pos--;
                            }
                        }
                        break;
                    }
                }
            } else {
                buckets[c - 'a'].push_back(result.size());
                result += c;
            }
        }

        return result;
    }
};

// Main function to test the clearStars function
int main() {
    Solution sol;

    string s1 = "aaba*";
    string s2 = "abc";
    string s3 = "cbacd*";

    cout << "Output for \"" << s1 << "\": " << sol.clearStars(s1) << endl; // Expected: "aab"
    cout << "Output for \"" << s2 << "\": " << sol.clearStars(s2) << endl; // Expected: "abc"
    cout << "Output for \"" << s3 << "\": " << sol.clearStars(s3) << endl; // Expected: "bcad"

    return 0;
}
