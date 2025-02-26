/*Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.*/


#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string S, int K) {
        if (K == S.length()) return "0";  // If we remove all digits, return "0"

        string result = "";  
        for (char digit : S) {
            while (!result.empty() && result.back() > digit && K > 0) {
                result.pop_back(); // Remove larger digits to get smaller number
                K--;
            }
            result.push_back(digit);
        }

        // Remove remaining digits from the end if K > 0
        while (K > 0 && !result.empty()) {
            result.pop_back();
            K--;
        }

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') start++;

        result = result.substr(start);

        // If result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};

int main() {
    Solution sol;
    cout << sol.removeKdigits("149811", 3) << endl;   // Output: "111"
    cout << sol.removeKdigits("1002991", 3) << endl;  // Output: "21"
    cout << sol.removeKdigits("10", 2) << endl;       // Output: "0"
    cout << sol.removeKdigits("123456", 2) << endl;   // Output: "1234"
    return 0;
}
