//You have n  tiles, where each tile has one letter tiles[i] printed on it.

//Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int backtrack(unordered_map<char, int> &freqMap) {
        int count = 0;
        for (auto &[ch, freq] : freqMap) {
            if (freq > 0) { 
                // Use the letter
                freq--;
                count += 1 + backtrack(freqMap); // Include current sequence and recurse
                freq++; // Restore count (backtrack)
            }
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freqMap;
        for (char ch : tiles) freqMap[ch]++; // Count character frequency
        return backtrack(freqMap);
    }
};

// Main function for testing
int main() {
    Solution obj;
    cout << obj.numTilePossibilities("AAB") << endl; // Output: 8
    cout << obj.numTilePossibilities("AAABBC") << endl; // Output: 188
    cout << obj.numTilePossibilities("V") << endl; // Output: 1
    return 0;
}

