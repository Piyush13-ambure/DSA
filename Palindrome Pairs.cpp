/*Given an array of strings arr[] of size N, find if there exists 2 strings arr[i] and arr[j] such that arr[i]+arr[j] is a palindrome i.e the concatenation of string arr[i] and arr[j] results into a palindrome.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function palindromepair() which takes the array arr[], its size N and returns true if palindrome pair exists and returns false otherwise.
The driver code itself prints 1 if returned value is true and prints 0 if returned value is false.
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Utility function to check if a string is a palindrome
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        unordered_set<string> wordSet;
        for (int i = 0; i < N; ++i) {
            wordSet.insert(arr[i]);
        }

        for (int i = 0; i < N; ++i) {
            string word = arr[i];
            int len = word.size();

            for (int j = 0; j <= len; ++j) {
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                if (isPalindrome(prefix)) {
                    string reversedSuffix = suffix;
                    reverse(reversedSuffix.begin(), reversedSuffix.end());
                    if (wordSet.count(reversedSuffix) && reversedSuffix != word) {
                        return true;
                    }
                }

                if (j != len && isPalindrome(suffix)) { // avoid duplicate check
                    string reversedPrefix = prefix;
                    reverse(reversedPrefix.begin(), reversedPrefix.end());
                    if (wordSet.count(reversedPrefix) && reversedPrefix != word) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// Main function to run the code
int main() {
    Solution sol;

    // Example 1
    string arr1[] = {"geekf", "geeks", "or", "keeg", "abc", "bc"};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << sol.palindromepair(N1, arr1) << endl; // Output: 1

    // Example 2
    string arr2[] = {"abc", "xyxcba", "geekst", "or", "bc"};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << sol.palindromepair(N2, arr2) << endl; // Output: 1

    // Example 3 - No palindrome pair
    string arr3[] = {"abc", "def", "ghi"};
    int N3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << sol.palindromepair(N3, arr3) << endl; // Output: 0

    return 0;
}
