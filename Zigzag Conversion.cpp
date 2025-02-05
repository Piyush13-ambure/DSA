//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR" Write the code that will take a string and make this conversion given a number of rows: string convert(string s, int numRows);



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; // No zigzag needed

        vector<string> rows(min(numRows, int(s.length())));
        int row = 0;
        bool goingDown = false;

        for (char ch : s) {
            rows[row] += ch;

            if (row == 0 || row == numRows - 1)
                goingDown = !goingDown; // Change direction at edges

            row += goingDown ? 1 : -1;
        }

        string result;
        for (const string& r : rows)
            result += r; // Concatenate all rows

        return result;
    }
};

int main() {
    Solution obj;
    cout << obj.convert("PAYPALISHIRING", 3) << endl; // Output: "PAHNAPLSIIGYIR"
    cout << obj.convert("PAYPALISHIRING", 4) << endl; // Output: "PINALSIGYAHRPI"
    cout << obj.convert("A", 1) << endl;             // Output: "A"
    return 0;
}
