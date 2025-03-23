//Given two strings A and B. Find the minimum number of steps required to transform string A into string B. The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int transform(string A, string B) {
        int n = A.length();
        int m = B.length();
        
        // If lengths are not equal, transformation is impossible
        if (n != m) return -1;

        // Frequency count of characters in both strings
        unordered_map<char, int> freq;
        for (char c : A) freq[c]++;
        for (char c : B) freq[c]--;

        // If frequency of any character is non-zero, transformation is impossible
        for (auto& entry : freq) {
            if (entry.second != 0) return -1;
        }

        // Find minimum moves required
        int i = n - 1, j = n - 1, moves = 0;
        
        while (i >= 0) {
            if (A[i] == B[j]) {
                j--; // Move to the previous character in B
            } else {
                moves++; // Need to move A[i] to the front
            }
            i--; // Move to the previous character in A
        }

        return moves;
    }
};

int main() {
    Solution sol;
    cout << sol.transform("abd", "bad") << endl;  // Output: 1
    cout << sol.transform("GeeksForGeeks", "ForGeeksGeeks") << endl;  // Output: 3
    return 0;
}
