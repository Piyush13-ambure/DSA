//Given a pattern string and a test string, If the pattern is preceded by a ^, the pattern(excluding the ^) will be matched with the starting position of the test string. Similarly, if it is succeded by a $, the pattern(excluding the $) will be matched with the ending position of the test string. If no such markers are present, it will be checked whether pattern is a substring of test.


#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int isPatternPresent(string S, string P) {
        if (P[0] == '^') {
            P = P.substr(1); // Remove the ^
            return S.find(P) == 0 ? 1 : 0;
        } else if (P.back() == '$') {
            P.pop_back(); // Remove the $
            size_t pos = S.rfind(P);
            return (pos != string::npos && pos + P.length() == S.length()) ? 1 : 0;
        } else {
            return S.find(P) != string::npos ? 1 : 0;
        }
    }
};

int main() {
    Solution sol;
    cout << sol.isPatternPresent("coaltar", "^coal") << endl; // Output: 1
    cout << sol.isPatternPresent("coaltar", "tar$") << endl; // Output: 1
    cout << sol.isPatternPresent("algorate", "rat") << endl; // Output: 1
    cout << sol.isPatternPresent("efgh", "abcd") << endl; // Output: 0
    return 0;
}

