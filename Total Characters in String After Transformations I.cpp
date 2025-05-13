/*You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7*/



#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> dp(26, 1); // dp[i] = resulting length of char 'a'+i after t transforms

        for (int step = 0; step < t; ++step) {
            vector<long long> new_dp(26);
            for (int i = 0; i < 26; ++i) {
                if (i == 25) {
                    // 'z' becomes "ab"
                    new_dp[i] = (dp[0] + dp[1]) % MOD;
                } else {
                    // other letters become next char
                    new_dp[i] = dp[i + 1];
                }
            }
            dp = new_dp;
        }

        long long result = 0;
        for (char c : s) {
            result = (result + dp[c - 'a']) % MOD;
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution sol;

    string s1 = "abcyy";
    int t1 = 2;
    cout << "Output 1: " << sol.lengthAfterTransformations(s1, t1) << endl;

    string s2 = "azbk";
    int t2 = 1;
    cout << "Output 2: " << sol.lengthAfterTransformations(s2, t2) << endl;

    return 0;
}
