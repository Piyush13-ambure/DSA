//Given a string S which only contains lowercase alphabets. Find the length of the longest substring of S such that the characters in it can be rearranged to form a palindrome.



#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubstring(string S) {
        unordered_map<int, int> maskIndex;
        int mask = 0, maxLength = 0;
        maskIndex[0] = -1; // Base case for full string palindrome
        
        for (int i = 0; i < S.size(); i++) {
            int bit = S[i] - 'a';
            mask ^= (1 << bit); // Toggle the bit
            
            // If the same mask was seen before, update maxLength
            if (maskIndex.find(mask) != maskIndex.end()) {
                maxLength = max(maxLength, i - maskIndex[mask]);
            } else {
                maskIndex[mask] = i;
            }

            // Check by toggling each bit (allowing one odd frequency character)
            for (int j = 0; j < 26; j++) {
                int newMask = mask ^ (1 << j);
                if (maskIndex.find(newMask) != maskIndex.end()) {
                    maxLength = max(maxLength, i - maskIndex[newMask]);
                }
            }
        }
        return maxLength;
    }
};

// Driver code
int main() {
    Solution sol;
    cout << sol.longestSubstring("aabe") << endl;  // Output: 3
    cout << sol.longestSubstring("adbabd") << endl;  // Output: 6
    return 0;
}
