/*Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lengths(operations.size() + 1);
        vector<int> shifts(operations.size() + 1, 0);

        lengths[0] = 1; // Initial word is "a"

        // Precompute the total length and shifts at each step
        for (int i = 0; i < operations.size(); ++i) {
            if (operations[i] == 0) {
                lengths[i + 1] = lengths[i] * 2;
                shifts[i + 1] = shifts[i];
            } else {
                lengths[i + 1] = lengths[i] * 2;
                shifts[i + 1] = (shifts[i] + 1) % 26;
            }
        }

        return helper(k - 1, operations, lengths, shifts, operations.size(), 0);
    }

private:
    char helper(long long k, vector<int>& operations, vector<long long>& lengths, vector<int>& shifts, int opIndex, int shift) {
        if (opIndex == 0) {
            // Base case: initial string is "a", apply shift
            return 'a' + (shift % 26);
        }

        long long leftLength = lengths[opIndex - 1];
        int op = operations[opIndex - 1];

        if (k < leftLength) {
            // Character is in the first part (original word)
            return helper(k, operations, lengths, shifts, opIndex - 1, shift);
        } else {
            // Character is in the appended part
            if (op == 0) {
                // Type 0: copied as is
                return helper(k - leftLength, operations, lengths, shifts, opIndex - 1, shift);
            } else {
                // Type 1: shifted by 1
                return helper(k - leftLength, operations, lengths, shifts, opIndex - 1, (shift + 1) % 26);
            }
        }
    }
};

// Example usage
int main() {
    Solution sol;

    long long k1 = 5;
    vector<int> ops1 = {0, 0, 0};
    cout << sol.kthCharacter(k1, ops1) << endl; // Output: a

    long long k2 = 10;
    vector<int> ops2 = {0, 1, 0, 1};
    cout << sol.kthCharacter(k2, ops2) << endl; // Output: b

    return 0;
}
