/*You are given two positive integers n and k.

An integer x is called k-palindromic if:

x is a palindrome.
x is divisible by k.
An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.

Return the count of good integers containing n digits.

Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Check if number is a palindrome
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    // Helper to generate palindromes of length n
    void generatePalindromes(int n, int k, unordered_set<string>& palSet) {
        int halfLen = (n + 1) / 2;
        int start = pow(10, halfLen - 1);
        int end = pow(10, halfLen);

        for (int i = start; i < end; ++i) {
            string left = to_string(i);
            string right = left;
            if (n % 2 == 1) right.pop_back(); // odd length

            reverse(right.begin(), right.end());
            string full = left + right;
            if (full[0] == '0') continue;

            long long val = stoll(full);
            if (val % k == 0) {
                sort(full.begin(), full.end());
                palSet.insert(full);
            }
        }
    }

    long long countGoodIntegers(int n, int k) {
        unordered_set<string> validPalSortedForms;

        // Step 1: Generate all valid palindromes that are divisible by k
        generatePalindromes(n, k, validPalSortedForms);

        // Step 2: For all n-digit numbers, check if they can be rearranged into a valid one
        int start = pow(10, n - 1);
        int end = pow(10, n);
        long long count = 0;

        for (int i = start; i < end; ++i) {
            string s = to_string(i);
            sort(s.begin(), s.end());
            if (validPalSortedForms.count(s)) {
                ++count;
            }
        }

        return count;
    }
};

// Main function to test
int main() {
    Solution sol;
    int n, k;

    // Sample Input 1
    n = 3, k = 5;
    cout << "Output for n = 3, k = 5: " << sol.countGoodIntegers(n, k) << endl;

    // Sample Input 2
    n = 1, k = 4;
    cout << "Output for n = 1, k = 4: " << sol.countGoodIntegers(n, k) << endl;

    // Sample Input 3
    n = 5, k = 6;
    cout << "Output for n = 5, k = 6: " << sol.countGoodIntegers(n, k) << endl;

    return 0;
}
