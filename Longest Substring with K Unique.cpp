//Given a string s, you need to print the size of the longest possible substring with exactly k unique characters. If no possible substring exists, print -1.

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> charCount;
        int maxLength = -1;
        int left = 0, right = 0;

        while (right < s.size()) {
            charCount[s[right]]++;

            // If the window has more than k unique characters, shrink it
            while (charCount.size() > k) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }

            // If the window has exactly k unique characters, calculate the length
            if (charCount.size() == k) {
                maxLength = max(maxLength, right - left + 1);
            }

            right++;
        }

        return maxLength;
    }
};

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;
    int result = sol.longestKSubstr(s, k);

    if (result == -1) {
        cout << "No substring with exactly " << k << " unique characters exists.\n";
    } else {
        cout << "The length of the longest substring with exactly " << k << " unique characters is: " << result << "\n";
    }

    return 0;
}
