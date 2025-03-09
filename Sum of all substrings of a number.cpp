/*Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, return answer modulo 109+7. 

Note: The number may have leading zeros.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to find the sum of all possible substrings of the given string.
    long long sumSubstrings(string s) {
        long long totalSum = 0, prevSum = 0, factor = 1;
        
        for (int i = 0; i < s.size(); i++) {
            prevSum = (prevSum * 10 + (s[i] - '0') * (i + 1)) % MOD;
            totalSum = (totalSum + prevSum) % MOD;
        }

        return totalSum;
    }
};

// Driver Code
int main() {
    Solution obj;
    cout << obj.sumSubstrings("1234") << endl;  // Output: 1670
    cout << obj.sumSubstrings("421") << endl;   // Output: 491
    return 0;
}
