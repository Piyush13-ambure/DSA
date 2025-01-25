//Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string
//Note: Answer can be very large, so, ouput will be answer modulo 109+7.


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int distinctSubsequences(string s) {
        const int MOD = 1000000007;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: there's one subsequence for the empty string

        unordered_map<char, int> last_occurrence; // To store the last occurrence of each character

        for (int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1] % MOD; // Include or exclude the current character

            // If the character has appeared before, subtract the subsequences that include its previous occurrence
            if (last_occurrence.find(s[i - 1]) != last_occurrence.end()) {
                dp[i] = (dp[i] - dp[last_occurrence[s[i - 1]] - 1] + MOD) % MOD;
            }

            // Update the last occurrence of the current character
            last_occurrence[s[i - 1]] = i;
        }

        return dp[n] - 1; // Subtract 1 to exclude the empty subsequence
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution solution;
    int result = solution.distinctSubsequences(s);

    cout << "Number of distinct subsequences: " << result << endl;

    return 0;
}
