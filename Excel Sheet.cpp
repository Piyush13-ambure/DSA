/*Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.*/


#include <iostream>
using namespace std;

class Solution {
public:
    string ExcelColumn(int N) {
        string result = "";
        while (N > 0) {
            N--; // Adjust for 0-based indexing
            char ch = 'A' + (N % 26);
            result = ch + result;
            N /= 26;
        }
        return result;
    }
};

int main() {
    int N;
    cin >> N;
    Solution sol;
    cout << sol.ExcelColumn(N) << endl;
    return 0;
}
