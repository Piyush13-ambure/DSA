/*Two strings are called k-anagrams if both of the below conditions are true.
1. Both have same number of characters.
2. Two strings can become anagram by changing at most k characters in a string.

Given two strings of lowercase alphabets and an integer value k, the task is to find if two strings are k-anagrams of each other or not.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        // If lengths are different, they cannot be k-anagrams
        if (s1.size() != s2.size())
            return false;
        
        unordered_map<char, int> freq1, freq2;
        
        // Count frequency of characters in both strings
        for (char ch : s1) freq1[ch]++;
        for (char ch : s2) freq2[ch]++;
        
        int changesNeeded = 0;
        
        // Calculate the number of changes required
        for (auto &entry : freq1) {
            char ch = entry.first;
            if (freq1[ch] > freq2[ch]) {
                changesNeeded += freq1[ch] - freq2[ch];
            }
        }
        
        // Check if we can convert within k changes
        return changesNeeded <= k;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        int k;
        cin >> k;
        Solution ob;
        if (ob.areKAnagrams(str1, str2, k))
            cout << "true\n";
        else
            cout << "false\n";
    }
}
