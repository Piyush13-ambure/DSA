//Given two strings denoting non-negative numbers s1 and s2. Calculate the sum of s1 and s2.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findSum(string &s1, string &s2) {
        int n1 = s1.size(), n2 = s2.size();
        int carry = 0;
        string result = "";

        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? s1[i] - '0' : 0;
            int digit2 = (j >= 0) ? s2[j] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
            i--, j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution obj;
    string s1, s2;
    cout << "Enter first number: ";
    cin >> s1;
    cout << "Enter second number: ";
    cin >> s2;

    cout << "Sum: " << obj.findSum(s1, s2) << endl;
    return 0;
}
