//Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

//Note: A palindrome string is a sequence of characters that reads the same forward and backward.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minChar(string &s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end()); // Reverse the string

        string temp = s + '#' + rev; // Concatenate original and reversed strings with a delimiter
        int m = temp.size();

        vector<int> lps(m, 0); // LPS array
        for (int i = 1; i < m; i++) {
            int j = lps[i - 1];

            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }

            if (temp[i] == temp[j]) {
                j++;
            }

            lps[i] = j;
        }

        // Minimum characters to add = length of the string - length of longest palindromic prefix
        return n - lps[m - 1];
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution solution;
    int result = solution.minChar(s);

    cout << "Minimum characters to add to make the string a palindrome: " << result << endl;

    return 0;
}
