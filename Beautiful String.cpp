/*You are given a  array query[] of size q. Each element of the array is an integer query[i], denote the length of a string s consisting of only lowercase english letters.
A string s is called beautiful if the length of its compressed form t is strictly less than the length of s.
The compressed form t of a string s is obtained by the following procedure:
  1. Group consecutive identical characters in S together.
  2. For each group, replace it with the character followed by the length of the group (as a decimal number).
  3. Concatenate all such replacements in order to form the string T.
For example:
   If s = "aaabbcccc", the groups are "aaa", "bb", "cccc", so t = "a3b2c4", and since the length of t is 6 < 8, the string is beautiful.
   If s = "ababab", the groups are "a", "b", "a", "b", "a", "b", so t = "a1b1a1b1a1b1", and since the length of t is 12 > 6, the string is not beautiful.
For each query You have to count how many strings of length n are beautiful. Since the number can be very large, output it modulo 1e9+7.*/

class Solution {
  public:
    long long modPow(long long a, long long n, long long mod) {
        if (mod == 1)
            return 0;
        long long res = 1, p = a % mod;
        while (n) {
            if (n & 1)
                res = res * p % mod;
            p = p * p % mod;
            n >>= 1;
        }
        return res;
    }

    vector<int> countBeautifulStrings(vector<int>& queries) {

        int mx = 0;
        for (auto it : queries) {
            mx = max(mx, it);
        }

        /* ---------- parameters ---------- */
        const long long MOD = 1e9 + 7;
        const int N = mx + 2;

        /* ---------- DP tables ---------- */
        vector<vector<long long>> dp(N, vector<long long>(N, 0));
        vector<vector<long long>> pref(N, vector<long long>(N, 0));
        vector<vector<long long>> pre(N, vector<long long>(N, 0));

        dp[0][0] = modPow(25, MOD - 2, MOD) * 26 % MOD;

        vector<int> ten = {1, 10, 100, 1000, 10000};
        for (int i = 1; i <= mx; ++i)
            pref[i][0] = dp[0][0];

        /* ---------- main DP ---------- */
        for (int i = 1; i <= mx; ++i) {
            for (int j = 1; j <= mx; ++j) {
                for (int k = 1; k <= 4; ++k) {
                    if (j - k - 1 < 0)
                        continue;
                    long long x = max(i - ten[k - 1] + 1, 0);
                    long long y = max(i - ten[k] + 1, 0);
                    long long add =
                        (pref[x][j - k - 1] - pref[y][j - k - 1] + MOD) % MOD;
                    dp[i][j] = (dp[i][j] + add * 25) % MOD;
                }
                pref[i + 1][j] = (pref[i][j] + dp[i][j]) % MOD;
            }
        }

        /* ---------- 2-D prefix for queries ---------- */
        for (int i = 1; i <= mx; ++i) {
            pre[i][1] = dp[i][1];
            for (int j = 2; j < i; ++j)
                pre[i][j] = (pre[i][j - 1] + dp[i][j]) % MOD;
        }

        /* ---------- answers ---------- */
        vector<int> ans;
        for (int x : queries)
            ans.push_back(pre[x][x - 1]);

        return ans;
    }
};
