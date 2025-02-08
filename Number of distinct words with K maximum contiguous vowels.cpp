//Find the number of unique words consisting of lowercase alphabets only of length N that can be formed with at-most K contiguous vowels. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int MOD = 1000000007;

    int kvowelwords(int N, int K) {
        vector<vector<long long>> dp(N+1, vector<long long>(K+1, 0));

        // Base case: There is 1 empty string
        dp[0][0] = 1;

        for (int n = 1; n <= N; n++) {
            for (int k = 0; k <= K; k++) {
                // If last letter is a consonant (21 choices)
                dp[n][k] = (dp[n-1][k] * 21) % MOD;

                // If last letter is a vowel (5 choices)
                if (k > 0) {
                    dp[n][k] = (dp[n][k] + dp[n-1][k-1] * 5) % MOD;
                }
            }
        }

        // Sum up all cases with at most K vowels
        long long result = 0;
        for (int j = 0; j <= K; j++) {
            result = (result + dp[N][j]) % MOD;
        }
        
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.kvowelwords(2, 0) << endl;  // Output: 441
    cout << sol.kvowelwords(1, 1) << endl;  // Output: 26
    return 0;
}
