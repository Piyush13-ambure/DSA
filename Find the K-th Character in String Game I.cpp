/*Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

Note that the character 'z' can be changed to 'a' in the operation.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        return helper(k, 'a');
    }

private:
    char helper(int k, char c) {
        if (k == 1) return c;

        int length = 1;
        while (2 * length < k) {
            length *= 2;
        }

        if (k <= length) {
            return helper(k, c);
        } else {
            // Find in incremented part
            char nextChar = (c - 'a' + 1) % 26 + 'a';
            return helper(k - length, nextChar);
        }
    }
};

// Main function for testing
int main() {
    Solution sol;

    int k;
    cout << "Enter k: ";
    cin >> k;

    cout << "The " << k << "-th character is: " << sol.kthCharacter(k) << endl;

    return 0;
}
