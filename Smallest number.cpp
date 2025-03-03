//Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible then return -1.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(int s, int d) {
        // If sum required is more than the maximum possible sum for d digits
        if (s > 9 * d) return "-1";

        vector<int> digits(d, 0); // Initialize all digits as 0
        s -= 1; // Reserve 1 for the most significant digit to avoid leading zero
        digits[0] = 1;

        // Fill the number from the least significant digit to the most
        for (int i = d - 1; i > 0; i--) {
            if (s >= 9) {
                digits[i] = 9;
                s -= 9;
            } else {
                digits[i] = s;
                s = 0;
            }
        }

        digits[0] += s; // Add remaining sum to the first digit

        // Convert digits array to a string
        string result = "";
        for (int digit : digits) {
            result += to_string(digit);
        }

        return result;
    }
};

// Driver Code
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
