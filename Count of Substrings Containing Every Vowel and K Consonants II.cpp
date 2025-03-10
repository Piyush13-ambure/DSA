/*You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;
        int left = 0;
        long long result = 0;

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int right = 0; right < n; ++right) {
            char current = word[right];

            // Update vowel and consonant count
            if (vowels.count(current)) {
                vowelCount[current]++;
            } else {
                consonantCount++;
            }

            // Ensure all vowels are present and consonant count == k
            while (vowelCount.size() == 5 && consonantCount == k) {
                result += (n - right); // Count all substrings starting at 'left' and ending at 'right' or later
                
                // Shrink window from the left
                char leftChar = word[left];
                if (vowels.count(leftChar)) {
                    vowelCount[leftChar]--;
                    if (vowelCount[leftChar] == 0) {
                        vowelCount.erase(leftChar);
                    }
                } else {
                    consonantCount--;
                }
                left++;
            }
        }

        return result;
    }
};

// Main function for testing
int main() {
    Solution sol;
    cout << sol.countOfSubstrings("aeioqq", 1) << endl;       // Output: 0
    cout << sol.countOfSubstrings("aeiou", 0) << endl;        // Output: 1
    cout << sol.countOfSubstrings("ieaouqqieaouqq", 1) << endl; // Output: 3
    return 0;
}
