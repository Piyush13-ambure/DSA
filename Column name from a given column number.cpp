//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string colName(long long int n) {
        string result = "";
        while (n > 0) {
            n--; // Adjusting to 0-based index
            char ch = 'A' + (n % 26);
            result = ch + result;
            n /= 26;
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.colName(28) << endl;       // Output: AB
    cout << sol.colName(13) << endl;       // Output: M
    cout << sol.colName(5473578) << endl;  // Output: KYJZF
    return 0;
}
