//Given a string s of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 


#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int atMostK(string& s, int k) {
        if (k == 0) return 0;
        
        unordered_map<char, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    cout << "Count of substrings with exactly " << k << " distinct characters: " << sol.countSubstr(s, k) << endl;

    return 0;
}
