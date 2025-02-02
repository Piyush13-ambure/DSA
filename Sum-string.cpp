//Given a string of digits, the task is to check if it is a ‘sum-string’. A string S is called a sum-string when it is broken down into more than one substring and the rightmost substring can be written as a sum of two substrings before it and the same is recursively true for substrings before it. Please note that, the rightmost substring shouldnot contain leading zeroes.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if a string is a sum-string
    bool checkSumString(string &s, int start, int len1, int len2) {
        string num1 = s.substr(start, len1);
        string num2 = s.substr(start + len1, len2);

        // Avoid numbers with leading zeros (except "0")
        if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) 
            return false;

        // Convert substrings to numbers
        long long n1 = stoll(num1);
        long long n2 = stoll(num2);
        string sumStr = to_string(n1 + n2);

        int sumStart = start + len1 + len2;
        int sumLen = sumStr.length();

        // Check if the expected sum substring matches the actual substring
        if (sumStart + sumLen > s.length() || s.substr(sumStart, sumLen) != sumStr)
            return false;

        // If we have reached the end of the string, it's a valid sum-string
        if (sumStart + sumLen == s.length())
            return true;

        // Recursively check the next part
        return checkSumString(s, start + len1, len2, sumLen);
    }

    int isSumString(string S) {
        int n = S.size();

        // Try all possible partitions for the first and second numbers
        for (int len1 = 1; len1 < n; len1++) {
            for (int len2 = 1; len1 + len2 < n; len2++) {
                if (checkSumString(S, 0, len1, len2))
                    return 1; // Valid sum-string
            }
        }
        return 0; // Not a sum-string
    }
};

// Driver code for testing
int main() {
    Solution sol;
    cout << sol.isSumString("122436") << endl;  // Output: 1 (12, 24, 36)
    cout << sol.isSumString("112358") << endl;  // Output: 1 (Fibonacci-like 1,1,2,3,5,8)
    cout << sol.isSumString("199100199") << endl; // Output: 1 (199,100,199)
    cout << sol.isSumString("1234") << endl;  // Output: 0 (No valid sequence)
    return 0;
}
