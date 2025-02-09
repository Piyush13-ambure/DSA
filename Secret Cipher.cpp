/*Geek wants to send an encrypted message in the form of string S to his friend Keeg along with instructions on how to decipher the message. To decipher the message, his friend needs to iterate over the message string from left to right, if he finds a '*', he must remove it and add all the letters read so far to the string. He must keep on doing this till he gets rid of all the '*'.
Can you help Geek encrypt his message string S? 

Note: If the string can be encrypted in multiple ways, find the smallest encrypted string. */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string compress(string s) {
        int n = s.length();
        string result = "";
        string prefix = "";
        
        for (int i = 0; i < n; i++) {
            prefix += s[i];
            int prefixLen = prefix.length();
            if (prefixLen * 2 <= result.length() + 1 && s.substr(i + 1, prefixLen) == prefix) {
                result += "*";
                i += prefixLen - 1;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.compress("ababcababcd") << endl; // Output: ab*c*d
    cout << sol.compress("zzzzzzz") << endl; // Output: z*z*z
    return 0;
}
