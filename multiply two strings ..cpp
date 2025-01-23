//iven two numbers as strings s1 and s2. Calculate their Product.
//Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.



#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to multiply two strings
    string multiplyStrings(string& s1, string& s2) {
        // Check for signs
        bool isNegative = false;
        if (s1[0] == '-') {
            isNegative = !isNegative;
            s1 = s1.substr(1);  // Remove the negative sign
        }
        if (s2[0] == '-') {
            isNegative = !isNegative;
            s2 = s2.substr(1);  // Remove the negative sign
        }

        // Remove leading zeros
        int i = 0;
        while (i < s1.length() && s1[i] == '0') i++;
        s1 = s1.substr(i);
        
        i = 0;
        while (i < s2.length() && s2[i] == '0') i++;
        s2 = s2.substr(i);
        
        // If either string is empty, the result is 0
        if (s1.empty() || s2.empty()) return "0";

        // Initialize result to 0
        int m = s1.size(), n = s2.size();
        vector<int> result(m + n, 0);

        // Perform multiplication digit by digit
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;    // Store current digit
                result[i + j] += sum / 10;       // Carry over the next digit
            }
        }

        // Convert the result to a string
        string res = "";
        for (int i = 0; i < result.size(); i++) {
            // Skip leading zeros
            if (!(res.empty() && result[i] == 0)) {
                res += to_string(result[i]);
            }
        }

        // Handle negative result
        if (isNegative) res = "-" + res;

        return res.empty() ? "0" : res;
    }
};

int main() {
    Solution solution;

    string s1 = "-123";
    string s2 = "456";

    cout << "Product: " << solution.multiplyStrings(s1, s2) << endl;

    return 0;
}
