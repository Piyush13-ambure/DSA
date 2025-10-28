/*Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lcs(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    for (int j = 0; j <= n; ++j) {
        dp[j] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int prev = dp[0];
        for (int j = 1; j <= n; ++j) {
            int temp = dp[j];
            if (s1[i - 1] == s2[j - 1])
                dp[j] = 1 + prev;
            else
                dp[j] = (dp[j - 1] > dp[j]) ? dp[j - 1] : dp[j];
            prev = temp;
        }
    }
    int result = dp[n];
    free(dp);
    return result;
}
