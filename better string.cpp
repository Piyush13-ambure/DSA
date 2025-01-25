//Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
//If both the strings have equal count of distinct subsequence then return str1.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to calculate the number of distinct subsequences
    int countDistinctSubsequences(string &str) {
        int n = str.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: empty string

        unordered_map<char, int> last; // To store the last occurrence of characters

        for (int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1]; // Add subsequences by including the current character

            char current = str[i - 1];
            if (last.find(current) != last.end()) {
                // Subtract subsequences counted before the last occurrence of the current character
                dp[i] -= dp[last[current] - 1];
            }

            // Update the last occurrence of the current character
            last[current] = i;
        }

        return dp[n];
    }

    // Function to find the better string
    string betterString(string str1, string str2) {
        int count1 = countDistinctSubsequences(str1);
        int count2 = countDistinctSubsequences(str2);

        if (count1 > count2) {
            return str1;
        } else if (count2 > count1) {
            return str2;
        } else {
            return str1; // Return str1 in case of a tie
        }
    }
};

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    Solution solution;
    string result = solution.betterString(str1, str2);

    cout << "The better string is: " << result << endl;

    return 0;
}
