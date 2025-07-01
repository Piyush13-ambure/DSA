/*Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.

You are given a string word, which represents the final output displayed on Alice's screen.

Return the total number of possible original strings that Alice might have intended to type.

 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        vector<pair<char, int>> groups;

        // Step 1: Group consecutive characters and their counts
        for (int i = 0; i < n;) {
            char ch = word[i];
            int j = i;
            while (j < n && word[j] == ch) j++;
            groups.push_back({ch, j - i});
            i = j;
        }

        int total = 1; // original word itself is always a valid option

        // Step 2: Try removing characters from each group (only once)
        for (int i = 0; i < groups.size(); i++) {
            int count = groups[i].second;
            if (count > 1) {
                total += count - 1;  // remove 1 to count-1 characters
            }
        }

        return total;
    }
};

// Helper function to run a test case
void runTest(string word) {
    Solution sol;
    cout << "Input: \"" << word << "\" => Output: " << sol.possibleStringCount(word) << endl;
}

int main() {
    runTest("abbcccc");   // Output: 5
    runTest("abcd");      // Output: 1
    runTest("aaaa");      // Output: 4
    runTest("aabb");      // Output: 3 (aabb, abb, aab)
    runTest("a");         // Output: 1
    return 0;
}
