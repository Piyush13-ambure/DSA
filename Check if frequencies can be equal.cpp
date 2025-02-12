//Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool sameFreq(string& s) {
        vector<int> freq(26, 0);
        unordered_map<int, int> countFreq;

        // Step 1: Count the frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: Count frequency occurrences
        for (int f : freq) {
            if (f > 0) countFreq[f]++;
        }

        // Step 3: Check valid conditions
        if (countFreq.size() == 1) return true;  // Already uniform

        if (countFreq.size() == 2) {
            auto it = countFreq.begin();
            int f1 = it->first, c1 = it->second;  // First frequency and its count
            it++;
            int f2 = it->first, c2 = it->second;  // Second frequency and its count

            // Case 1: One frequency occurs once and is greater by 1
            if ((c1 == 1 && f1 == f2 + 1) || (c2 == 1 && f2 == f1 + 1)) return true;

            // Case 2: One frequency is 1 and appears only once
            if ((c1 == 1 && f1 == 1) || (c2 == 1 && f2 == 1)) return true;
        }

        return false;
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    vector<string> testCases = {"xyyz", "xxxxyyzz", "aabbccc"};
    
    for (string s : testCases) {
        cout << "Input: " << s << " -> Output: " << (sol.sameFreq(s) ? "true" : "false") << endl;
    }
    
    return 0;
}
