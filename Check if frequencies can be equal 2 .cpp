//Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.


 #include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool sameFreq(string& s) {
        unordered_map<char, int> freq;
        
        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Store frequency counts
        unordered_map<int, int> freqCount;
        for (auto& p : freq) {
            freqCount[p.second]++;
        }

        // If there's only one unique frequency, return true (already uniform)
        if (freqCount.size() == 1) {
            return true;
        }

        // If there are more than two distinct frequencies, it's not possible
        if (freqCount.size() > 2) {
            return false;
        }

        // Get the two frequency values
        auto it = freqCount.begin();
        int freq1 = it->first, count1 = it->second;
        it++;
        int freq2 = it->first, count2 = it->second;

        // Possible cases for making frequency uniform:
        // 1. If one frequency appears only once and removing it makes all the same
        //    Example: "aabbccc" (2,2,3) → Remove one 'c' to make (2,2,2)
        if ((count1 == 1 && (freq1 - 1 == freq2 || freq1 - 1 == 0)) ||
            (count2 == 1 && (freq2 - 1 == freq1 || freq2 - 1 == 0))) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter the string: ";
    cin >> s;

    if (solution.sameFreq(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
