//Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

//Cases for atoi() conversion:

//Skip any leading whitespaces.
//Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
//Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
//If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.



#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(char *s) {
        int i = 0;
        int sign = 1; // Default to positive
        long result = 0; // Use long to handle overflow during computation

        // Step 1: Skip leading whitespaces
        while (s[i] == ' ') {
            i++;
        }

        // Step 2: Check for a sign
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Process digits
        while (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');

            // Step 4: Check for overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        // Step 5: Apply sign and return result
        return static_cast<int>(result * sign);
    }
};

int main() {
    Solution solution;

    char s1[] = "   -42";
    char s2[] = "4193 with words";
    char s3[] = "words and 987";
    char s4[] = "-91283472332";

    cout << "Converted value: " << solution.myAtoi(s1) << endl; // Output: -42
    cout << "Converted value: " << solution.myAtoi(s2) << endl; // Output: 4193
    cout << "Converted value: " << solution.myAtoi(s3) << endl; // Output: 0
    cout << "Converted value: " << solution.myAtoi(s4) << endl; // Output: -2147483648

    return 0;
}
