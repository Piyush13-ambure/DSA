//Given a number k and string s of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of s at most k times.


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string maxNum; // Store the maximum number found

    void findMaxHelper(string& s, int k, int index) {
        if (k == 0) return; // If no swaps left, return

        int n = s.length();
        char maxDigit = s[index];

        // Find the maximum digit in the remaining part
        for (int i = index + 1; i < n; i++) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
            }
        }

        // If the current digit is already the max, move forward
        if (maxDigit == s[index]) {
            findMaxHelper(s, k, index + 1);
            return;
        }

        // Try all possible swaps with the maximum digit found
        for (int i = index + 1; i < n; i++) {
            if (s[i] == maxDigit) {
                swap(s[index], s[i]);

                // Update maxNum if this arrangement is better
                if (s > maxNum) {
                    maxNum = s;
                }

                // Recur for next index with k-1 swaps remaining
                findMaxHelper(s, k - 1, index + 1);

                // Backtrack
                swap(s[index], s[i]);
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        maxNum = s;
        findMaxHelper(s, k, 0);
        return maxNum;
    }
};

int main() {
    Solution solution;

    string s1 = "1234567";
    int k1 = 4;
    cout << "Output: " << solution.findMaximumNum(s1, k1) << endl; // Expected: 7654321

    string s2 = "3435335";
    int k2 = 3;
    cout << "Output: " << solution.findMaximumNum(s2, k2) << endl; // Expected: 5543333

    string s3 = "1034";
    int k3 = 2;
    cout << "Output: " << solution.findMaximumNum(s3, k3) << endl; // Expected: 4301

    return 0;
}
